# mario less comfortable - Owen FitzGerald 25/10/2021
from cs50 import get_int

# delcare global variables
height = 0
blanks = 0

# get user input until range 1-8
while height < 1 or height > 8:
    height = int(get_int("Enter height between 1-8: "))

# draw result
for i in range(height+1):
    print("#" * blanks)
    print("." * (height-1), end="")
    blanks += 1
    height -= 1