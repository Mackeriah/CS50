
'''
# print("Hello, world")

x = 20
y = 20

val_name = input("Enter your name: ")
val_age = input("Enter your age: ")
print(f"{val_name} is {val_age}")

if x < y:
    print("x is less than y")
elif x > y:
    print("x is more than y")
else:
    print("x is the same as y")

#i = 10
#while i > 0:
#    print("Hello, world")
#    i -= 1


# this is called a list in Python
for i in [0, 1, 2]: # give me a variable called i and set to 0, then set to 1 and on final interation set to 2
    print("Hello, world")


# do this number of times
for i in range(3):
    print("Hello, world")

print("")

# increment by 2 (start, stop, step)
for i in range(0, 10, 2):
    print(f"{i} Hello, world")



x = int(input("x:"))
y = int(input("y:"))
print(x + y)


s = input("Do you agree? ")

if s.lower() in ["yes", "y"]:
    print("User agreed.")
if s.lower() in ["no", "n"]:
    print("Didn't agree!")

'''

for i in range(0, 20, 2):
    print(i)

