import csv

# create a dictionary
favourite_songs = {}

with open ("songs.csv") as file:
    reader = csv.DictReader(file)
    for row in reader:
        year = row["Release Year"]

        # if current row's year isn't in the dictionary...
        if year not in favourite_songs:
            # ... create it and assign value 0 to it's key
            favourite_songs[year] = 0
        # each time year read, increment by 1 (also now works for brand new entires and pre-existing)
        favourite_songs[year] += 1

# define new function called f which takes a year as it's argument (which are from our dictionary)
def f(year):
    # and returns the value for each key
    # so if Breaking Bad is the first key and has a value of 76 this would be returned for that year
    return favourite_songs[year]

for year in sorted(favourite_songs, key=f, reverse=True):
    print(f"Year:{year}, Value:{favourite_songs[year]}")
