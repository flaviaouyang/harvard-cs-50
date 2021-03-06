# Section E: Flask

## Web Programming

- `https://www.example.com/path`
- `https://www.example.com/route?key=value`
- `http-server` is not sufficient to **parse** url with routes

## Flask

```python
from flask import Flask
```

- **repo structure**:
	- `app.py`: python script, main app
	- `static folder`: not changing file, eg. images, css
	- `template`: html files
	- `requirements.txt`: list names of all libraries
- `app.py`

```python
from flask import Flask, render_template, request

app = Flask(__name__) 
# name refers to the name of the current file
# this line tells python to turn this file into a flask application

# this @ thingy is called a decorator
# decorators modify another function
@app.route("/")
# define a route for slash /
def index():
    return render_template("index.html")
```

- Run: `flask run`
- **Incorporating variables** into webpage:

```python
def index():
    name = request.args.get('name')
    return render-template("index.html", name=name)
```

```html
<h1>
    Hello, {{name}}!
</h1>
```

```url
http://127.0.0.1:5000/?name=Amelia
```

- A better user experience:

```python
@app.route("/greet")
def index():
    return render_template("index.html")

@app.route("/greet")
def greet():
    	name = request.args.get("name", "world")
        return render_template("greet.html", name = name)
```

```html
<form  action="/greet" method="get">
    <input autocomplete="off" autofocus name="name" placeholder="Name" type="text">
    <input type="submit">
</form>
```

```html
<h1>
    Hello, {{name}}!
</h1>
```

## Template

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title></title>
</head>
<body>
   {% raw %}{% block body %}{% endblock %}{% endraw %}
</body>
</html>
```

```html
{% raw %}{% extends "layout.html" %}{% endraw %}
{% raw %}{% body block %}{% endraw %}
<h1>Hi, there!</h1>
<h2>What should I call you?</h2>
<form action="/greet" method="get">
    <input required autocomplete="off" autofocus name="name" placeholder="Name" type="text">
    <input type="submit">
</form>
{% raw %}{% endblock %}{% endraw %}
```

## `POST`

- change the method of form to `post` from `get`
	- `ERROR: Method not allowed`
	- Change `@app.route("/greet, methods=["POST"])`
	- displays only `hello, world`
	- `request.args` for `get`; `request.form` for `post`
	- works now
- **MVC Paradiam**: Model-View-Controller
	- `app.py` -> **controller**
		-  ???business logic???, code that manages our application overall, given user input
	-  `*.html` -> **view**
		- templates and visuals for the user interface, like the HTML and CSS that the user will see and interact with
	- `databases, etc` -> **model**
		- our application???s data, such as a SQL database or CSV file

## Storing Data

```python
from flask import Flask, render_template, request, redirect

app = Flask(__name__)

REGISTRY = {}

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
    REGISTRY[name] = book

    # confirm registration
    return redirect('/registry')

@app.route('/registry')
def registry():
    return render_template('registry.html', registry = REGISTRY)

@app.route('/more')
def more():
    return render_template('index.html', books = BOOK)
```
