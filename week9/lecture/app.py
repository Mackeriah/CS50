from flask import Flask, render_template, request

# this tells python to turn the file into a Flash application
app = Flask(__name__)

# tell Flask when to run this function
@app.route("/")
def index():    
    # print to the users screen
    return render_template("index.html")

@app.route("/greet")
def greet():
    name = request.args.get("name")
    return render_template("greet.html", name=name)