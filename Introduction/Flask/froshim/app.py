from flask import Flask, render_template, request

app = Flask(__name__)

BOOK = [
    "The Bell Jar",
    "The Outsider",
    "Catcher in the Rye"
]

@app.route('/')
def index():
    return render_template('index.html', books = BOOK)

@app.route('/register', methods=['POST'])
def register():
    
    # validate user input
    if not request.form.get('name') or request.form.get("book") not in BOOK:
        return render_template('failure.html')
    
    # confirm registration
    return render_template('success.html')