import csv

# open file in append mode
with open("phonebook.csv", "a") as file:

    name = input("Name: ")
    number = input("Number: ")
    writer = csv.writer(file)
    writer.writerow([name, number])


'''
# define dictiionary
people = {
    "Owen": "+61-420-519-009",
    "Carly": "+61-420-519-008",
    "Mike": "+61-50845"
}

# store user input
name = input("Name: ")

if name in people:
    print(f"Number: {people[name]}")


'''