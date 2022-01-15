# HTML, CSS and JavaScript

---

## The Internet

- Internet is **the network of networks** of computers communicating with one another.
	- `internet` = `interconnected`+`networks`
- **Routers** are <u>specialized computers with CPUs and memory</u>, whose purpose is to relay data cross cables or wireless technologies, between other devices on the internet.
	- **???** are routers and servers the same thing
- **Protocols** are <u>a set of standard conventions</u> that the world has agreed upon for computers to communicate with.
- **TCP/IP** are two protocols for sending data between two computers.
  - consider sending mail, one would put return address and recipient address on the envelope 
  - This envelope in computer science will be referred to as **packets** of information.
- **IP** stands for <u>internet protocol</u>, a protocol supported by modern computer's software which includes a standard way for computers to address each other.
  - `#.#.#.#`
  - **IP address** is unique address for computer connected to the internet.
  - In routers' memory, there is a table mapping IP addresses to cables each connected to other routers.
- **DNS** stands for <u>Domain Name System</u> which is another technology that translate domain names to IP addresses.
  - DNS is generally provided as a service by the nearest internet service provider or **ISP**.
- **TCP** stands for <u>Transmission Control Protocol</u>. 
  - TCP is one final protocol that allows a single server, at the same IP address, to provide multiple services through the use of **a port number**, a small integer added to the IP address.

## The Web

- **HTTP**: standardizes how web browsers and web servers communicate within TCP/IP packets

	- **HTTPS**: is the secure version of **HTTP**; ensures that the content of the packets are encrypted

- **URL**: `https://www.example.com/folder/file.html`

- Commands supported by HTTP:

	- `POST`

	- `GET`:

	```http
	GET / HTTP/1.1 -> version of HTTP
	Host: www.example.com
	...
	```

	```http
	Response:
	HTTTP/1.1 200 OK
	Content-Type: text/html
	...
	```

- Check HTTP requests: `Inspect Element -> Network -> select one of the requests -> Request Headers -> View source`

	- with **terminal**: `curl -I -X GET http://example.com`

```bash
flaviaouyang@MacBook-Pro HTML CSS JavaScript % curl -I -X GET https://www.cs.mcgill.ca/

HTTP/1.1 200 OK
Date: Sat, 15 Jan 2022 13:38:17 GMT
Server: Apache
X-Frame-Options: DENY
X-Content-Type-Options: nosniff
Vary: Accept-Encoding
Content-Type: text/html; charset=utf-8
X-Varnish: 101571209
Age: 0
Via: 1.1 varnish-v4
Accept-Ranges: bytes
Transfer-Encoding: chunked
Connection: keep-alive
```

```bash
flaviaouyang@MacBook-Pro HTML CSS JavaScript % curl -I -X GET cs.mcgill.ca      

HTTP/1.1 301 Moved Permanently
Date: Sat, 15 Jan 2022 13:39:40 GMT
Server: Varnish
X-Varnish: 103286220
Location: https://www.cs.mcgill.ca/
Content-Length: 0
Connection: keep-alive
```

```bash
flaviaouyang@MacBook-Pro HTML CSS JavaScript % curl -I -X GET https://cs.mcgill.ca/thisfiledoesnotexist/

HTTP/1.1 404 Not Found
Date: Sat, 15 Jan 2022 13:44:43 GMT
Server: Apache
Content-Length: 10740
X-Frame-Options: DENY
Vary: Cookie
X-Content-Type-Options: nosniff
Content-Type: text/html; charset=utf-8
X-Varnish: 102682836
Age: 0
Via: 1.1 varnish-v4
Connection: keep-alive
```

## HTML

- **http-server**
- **Video**:

```html
<video autoplay loop muted>
	<source src="example.mp4" type="video/mp4">
</video>
```

- **responsive**: 

```html
<head>
    <meta name="viewport" content="initial-scale=1, width=device-width">
</head>
```

- `https://www.example.com/path?key=value`:
	- `https://www.google.com/search?q=cats&...`: `q` stands for query which **has a value of cats** along with other keys and values
- in HMTL, we can create a form that takes user input and send it to google search engine

```html
<!DOCTYPE html>

<html lang="en">
    <head>
        <title>search</title>
    </head>
    <body>
        <form action="https://www.google.com/search" method="get">
            <input name="q" type="text">
            <input type="submit">
        </form>
    </body>
</html>
```

## JavaScript

- Implement a form with **autocomplete**:

```html
<!DOCTYPE html>
  
<html lang="en">
  
    <head>
        <title>autocomplete</title>
    </head>
  
    <body>
  
        <input autocomplete="off" autofocus placeholder="Query" type="text">
  
        <ul></ul>
  
        <script src="large.js"></script>
        <script>
      
            let input = document.querySelector('input');
            input.addEventListener('keyup', function(event) {
                let html = '';
                if (input.value) {
                    for (word of WORDS) {
                        if (word.startsWith(input.value)) {
                            html += `<li>${word}</li>`;
                        }
                    }
                }
                document.querySelector('ul').innerHTML = html;
            });
  
        </script>
  
    </body>
</html>
```

- ask for user's **geolocation**:

```html
<!DOCTYPE html>
  
<html lang="en">
    <head>
        <title>geolocation</title>
    </head>
    <body>
        <script>
          
            navigator.geolocation.getCurrentPosition(function(position) {
                document.write(position.coords.latitude + ", " + position.coords.longitude);
            });
  
        </script>
    </body>
</html>
```