import cs50
from flask import Flask, render_template, request, redirect
from cs50 import SQL

app = Flask(__name__)

db = SQL.connect('froshim.db', check_same_thread=False)

BOOK = [
    "The Bell Jar",
    "The Outsider",
    "Catcher in the Rye"
]


@app.route('/')
def index():
    return render_template('index.html', books=BOOK)


@app.route('/register', methods=['POST'])
def register():

    # validate name
    name = request.form.get('name')
    book = request.form.get('book')
    if not name and book:
        return render_template('failure.html', message='Missing Name')

    # validate book
    if not book and name:
        return render_template('failure.html', message='Must select a book')
    
    if book not in BOOK and name:
        return render_template('failure.html', message='Invalid book')

    # validate both
    if not book and not name:
        return render_template('failure.html', message='Both Name and Book Selections Missing.')
    
    # save register to memory
    # REGISTRY[name] = book
    
    # using SQL to remember
    db.execute("INSERT INTO registry (name, book) VALUES(?, ?)", (name, book))
    
    # confirm registration
    return redirect('/registry')

@app.route('/registry')
def registry():

    return render_template('registry.html', registry = db.execute("SELECT * FROM registry"))

@app.route('/more')
def more():
    return render_template('index.html', books = BOOK)
