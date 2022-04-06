# mario less comfortable - Owen FitzGerald 25/10/2021
from cs50 import get_int

# delcare global variables
height = 0
hashes = 0

# get user input until range 1-8
while height < 1 or height > 8:
    height = int(get_int("Enter height between 1-8: "))

count = False

# draw result
for i in range(height+1):
    print("#" * hashes, end="")
    if count == True:
        print("  ", end="")
    elif count == False:
        count = True
    print("#" * hashes)
    print(" " * (height-1), end="")
    hashes += 1
    height -= 1
