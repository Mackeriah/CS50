import csv

from cs50 import SQL

# this is a quick way to create a file in pythong, by opening in write and then closing
open("shows.db", "w").close()

# this opens the file we just created
db = SQL("sqlite:///shows.db")

# create table with 2 columns and set id as the primary key
db.execute("CREATE TABLE shows (id INTEGER, title TEXT, PRIMARY KEY(id))")

# create genres table and point foreign key show_id column at shows table id column
db.execute("CREATE TABLE genres (show_id INTEGER, genre TEXT, FOREIGN KEY(show_id) REFERENCES shows(id))")


with open ("Favorite TV Shows - Form Responses 1.csv") as file:
    reader = csv.DictReader(file)
    for row in reader:

        # get current title, strip blanks and upper case it
        title = row["title"].strip().upper()

        #  in the shows DB in the title column each show title (and store the return value as the ID)
        id = db.execute("INSERT INTO shows (title) VALUES(?)", title)

        # shows may have multiple genres so this line uses the split function to split them
        for genre in row["genres"].split(", "):

            # the end of this line is the same as the C printf syntax btw
            # so first ? relates to id and second to the genre for the show
            # so if People Like Us had ID 50845 and genres Comedy, Drama, Horror(!) then
            # the For loop would use 50845, Comedy for the first time through For loop
            # then 50845, Drama and finaly 50845, Horror
            db.execute("INSERT INTO genres (show_id, genre) VALUES (?, ?)", id, genre)


