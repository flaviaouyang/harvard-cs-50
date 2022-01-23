import os
import re

from flask import Flask, render_template, request
from flask_mail import Mail, Message

app = Flask(__name__)
mail = Mail(app)


@app.route('/')
def index():
    return render_template("index.html")

