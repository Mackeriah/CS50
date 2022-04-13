import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    # get the current user ID
    user_id = session["user_id"]

    # get user related information to display on / page
    # SUM shares so that each symbol only has one line
    userStocks = db.execute(
        "SELECT name, price, symbol, SUM(shares) as ownedShares FROM transactions WHERE user_id = ? GROUP BY symbol", user_id)

    # get cash information for user from dictionary
    userCashBalance = db.execute("SELECT cash FROM users WHERE id = ?", user_id)[0]["cash"]

    # can't work out why I couldn't get it to work using userCashBalance in For loop  /shrug/ Seems hacky but works!
    shareTotalValue = userCashBalance

    # calculate total share value per line
    for stock in userStocks:
        shareTotalValue += stock["price"] * stock["ownedShares"]

    # first is variable name from html, second is variable name from python
    return render_template("index.html", usd=usd, total=shareTotalValue, cash=userCashBalance, stocks=userStocks)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "GET":
        return render_template("buy.html")
    else:
        # get symbol info and uppercase it
        symbol = request.form.get("symbol").upper()

        # use lookup function to get info on product and store in variable
        product = lookup(symbol)

        # check that user entered a symbol and that it exists
        if not symbol or not product:
            return apology("Symbol unavailable or not entered")

        # really struggled with this damn part but eventually found a workaround with some help online, phew!!!
        # still think my original approach must work somehow though!
        try:
            # get what user entered in shares field and cast to int
            shares = int(request.form.get("shares"))
        except:
            # if we can't cast to int then error out
            return apology("Sorry, you can only buy whole shares")

        # check that share is a positive int
        if shares <= 0:
            return apology("Share cannot be zero or negative")

        # get currently signed in user id
        user_id = session["user_id"]

        # get user cash for current user
        userCash = db.execute("SELECT cash FROM users WHERE id = ?", user_id)[0]["cash"]

        productName = product["name"]
        productPrice = product["price"]
        transactionCost = productPrice * shares

        # check if user has enough money for purchase
        if userCash < transactionCost:
            return apology("Insufficient funds")
        else:
            # reduce user cash balance
            db.execute("UPDATE users SET cash = ? WHERE id = ?", userCash - transactionCost, user_id)
            # add to transactions table
            db.execute("INSERT INTO transactions (user_id, name, shares, price, type, symbol) VALUES (?, ?, ?, ?, ?, ?)",
                       user_id, productName, shares, productPrice, 'buy', symbol)

        # return user to home
        return redirect("/")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    # get user id
    user_id = session["user_id"]
    transactionHistory = db.execute("SELECT * FROM transactions WHERE user_id = ?", user_id)
    return render_template("history.html", transactions=transactionHistory)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    # display quote.html on GET
    if request.method == "GET":
        return render_template("quote.html")
    else:
        # get value user entered in symbol field and store in symbol variable
        symbol = request.form.get("symbol")

        # if there was nothing entered
        if not symbol:
            return apology("No symbol entered")

        # use lookup function to get info and store in variable
        productInfo = lookup(symbol)

        # if the product doesn't exist
        if not productInfo:
            return apology("Sorry that product was not found")

        # if symbol was found, display required info
        # reminder: first name is one in HTML, second is variable declared above
        return render_template("quoted.html", usd=usd, product=productInfo)


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    # display page if not POST
    if request.method == "GET":
        return render_template("register.html")

    else:
        userName = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")

        # handle blank password
        if not password:
            return apology("Password cannot be blank")

        # if confirmation password blank
        if not confirmation:
            return apology("Confirmation password cannot be blank")

        # check if passwords don't match
        if password != confirmation:
            return apology("Passwords must match")

        # handle blank username
        if not userName:
            return apology("Username required")

        # hash password for registration
        passwordHash = generate_password_hash(password)

        # add user to users table (https://docs.python.org/3/tutorial/errors.html)
        try:
            db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", userName, passwordHash)
            return redirect("/")
        except:
            # if username already exists in DB give apology
            return apology("User already registered!")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    if request.method == "GET":

        # get user id
        user_id = session["user_id"]

        # get symbols user owns
        userOwnedSymbols = db.execute("SELECT symbol FROM transactions WHERE user_id = ? GROUP BY symbol", user_id)

        # display data
        return render_template("sell.html", symbols=userOwnedSymbols)

    else:
        # get user id
        user_id = session["user_id"]

        # capture symbols
        symbol = request.form.get("symbol")

        # capture shares qty
        shares = int(request.form.get("shares"))

        # handle negative number to sell
        if shares <= 0:
            return apology("Positive number only please")

        # get prices and names of what user owns
        productPrice = lookup(symbol)["price"]
        productName = lookup(symbol)["name"]
        sellPrice = shares * productPrice

        # get number of shares owned by user and group them
        userSharesOwned = db.execute(
            "SELECT shares FROM transactions WHERE user_id = ? AND symbol = ? GROUP BY symbol", user_id, symbol)[0]["shares"]

        # if user boldly trying to sell more shares than the own, politely decline
        if userSharesOwned < shares:
            return apology("Nice try, but you don't have that many!")

        # get user current cash balance
        userCash = db.execute("SELECT cash FROM users WHERE id = ?", user_id)[0]["cash"]

        # update user's cash balance to reflect the sold share(s)
        db.execute("UPDATE users SET cash = ? WHERE id = ?", userCash + sellPrice, user_id)
        db.execute("INSERT INTO transactions (user_id, name, shares, price, type, symbol) VALUES (?, ?, ?, ?, ?, ?)",
                   user_id, productName, -shares, productPrice, 'sell', symbol)

        # return user to home
        return redirect("/")