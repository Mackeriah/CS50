from flask import Flask, render_template, request

# this tells python to turn the file into a Flash application
app = Flask(__name__)

# tell Flask when to run this function
@app.route("/")
def index():    
    # render index.html to the users screen
    return render_template("index.html")

@app.route("/greet", methods=["POST"])
def greet():
    name = request.form.get("name", "world")
    return render_template("greet.html", name=name)

