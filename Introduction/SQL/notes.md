# Section C: SQL

##  Data Processing

- **Database** is a file or programs that stores data for us.
- A CSV file is a **flat-file database** where the data for each column is separate by commas 

## Relational databases

- **Relational databases** are programs that store data, ultimately in files, but with additional data structures and interfaces that allow us to search and store data more efficiently.

## SQL

- **Structured Query Language** 
- **CRUD**
	- `CREATE`
	- `READ`
	- `UPDATE`
	- `DELETE`
- SQL:
	- `CREATE`, `INSERT`
	- `SELECT`
	- `UPDATE`
	- `DELETE`
- Create a table: `CREATE TABLE table (column type, ...)`;
- Getting data: `SELECT columns FROM table;  `
- Clean data up to upper case: `SELECT DISTINCT(UPPER(columns)) FROM table;`
- We can add more clauses or phrases to modify our query:
	- `WHERE`: matching results in a strict conditions
	- `LIKE`: matching results in a less strict conditions
	- `ORDER BY`: ordering results in some way
	- `LIMIT`:limiting the number of results
	- `GROUP BY`: grouping results in some way
-  Filter rows by titles

```sqlite
SELECT title FROM shows WHERE title = "the office";
SELECT title FROM shows WHERE title LIKE "%office%";
SELECT DISTINCT(UPPER(title)) FROM shows ORDER BY UPPER(title); 
```

