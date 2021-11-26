import csv

# with open("/Users/flaviaouyang/CS50/SQL/name.csv", "r") as file:
#     reader = csv.reader(file)
#     next(reader)
#     for row in reader:
#         print(row[2])

with open("/Users/flaviaouyang/CS50/SQL/name.csv", "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        print(row["name"])
