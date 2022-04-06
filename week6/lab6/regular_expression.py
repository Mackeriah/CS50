
from cs50 import get_string
from cs50 import get_int
import re

card_number = input("Please enter your credit card number: ")
#print(f"{card_number}")


pattern_numeric = re.compile('[0-9]')
pattern_non_numeric = re.compile('\D')


m = pattern_numeric.match(card_number)
m2 = pattern_numeric.findall(card_number)
m3 = len(pattern_numeric.findall(card_number))

n = pattern_non_numeric.match(card_number)
n2 = pattern_non_numeric.findall(card_number)
n3 = len(pattern_non_numeric.findall(card_number))

print("checking for numbers")
print(m)
print(m2)
print(m3)

print("checking for non-numbers")
print(n)
print(n2)
print(n3)

'''
pattern = '[a-z]+'
#pattern = '\d+'
text = 'Hello Owen'
#length = len(re.findall(pattern, text))
length = len(re.finditer(pattern, text))

print(length)

line = "Owen Ellis FitzGerald"
regex = re.compile('\s')
output = regex.split(line)
print(output)
'''