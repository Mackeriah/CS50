import csv

# create a dictionary
favourite_shows = {}

with open ("Favorite TV Shows - Form Responses 1.csv") as file:
    reader = csv.DictReader(file)
    for row in reader:
        # add current row's title to the dictionary
        # strip leading and trailing spaces and make it uppercase
        title = row["title"].strip().upper()

        # if current row's title isn't in the dictionary...
        if title not in favourite_shows:
            # ... create it and assign value 0 to it's key
            favourite_shows[title] = 0
        # each time title read, increment by 1 (also now works for brand new entires and pre-existing)
        favourite_shows[title] += 1

for title in sorted(favourite_shows, key=lambda title: favourite_shows[title], reverse=True):
    print(title, favourite_shows[title]) 


# define new function called f which takes a title as it's argument (which are from our dictionary)
# def f(title):
#     # and returns the value for each key
#     # so if Breaking Bad is the first key and has a value of 76 this would be returned for that title
#     return favourite_shows[title]


# for title in sorted(favourite_shows, key=f, reverse=True):
#     print(title, favourite_shows[title])



