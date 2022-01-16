from flask import Flask, render_template, request

app = Flask(__name__) 
# name refers to the name of the current file
# this line tells python to turn this file into a flask application

# this @ thingy is called a decorator
# decorators modify another function
@app.route("/")
# define a route for slash /
def index():
    # request a name from user
    # name = request.args.get("name")
    return render_template("index.html")

@app.route("/greet", methods=["POST"])
def greet():
    # second parameter is the default value
    name = request.form.get("name", default="world")
    return render_template("greet.html", name=name)