# Validate user entered credit card number - Owen FitzGerald 27/10/2021

from cs50 import get_string
from cs50 import get_int
import re #regular expression library

def main():

    card_number = validate_card_number()
    # loop until valid number entered
    while card_number == False:
        card_number = validate_card_number()

    valid_card = luhn_algorithm(card_number)
    if valid_card == True:
        #print("Hurrah!")
        provider = get_provider(card_number)

    else:
        print("Luhn: INVALID")
        exit()



# check card number contains only digits and is a valid length
def validate_card_number():

    # get card number from user
    card_number = ask_for_card_number()

    digits = re.compile('[0-9]')                                # look for numeric
    count_digits = len(digits.findall(card_number))             # count numeric
    non_numeric = re.compile('\D')                              # look for non-numeric
    count_non_numeric = len(non_numeric.findall(card_number))   # count non-numeric

    # print(f"Numbers: {count_digits}")
    # print(f"Non-numbers found: {count_non_numeric} {n2}")

    # TESTING ONLY - return each card digit
    # match = [digits.findall(card_number)]
    #print(match)

    # check if only digits and not beyond max length
    if count_non_numeric != 0 or count_digits > 16:
        return False
    else:
        return card_number

# get credit card number from user
def ask_for_card_number():
    card_number = input("Please enter your credit card number: ")
    return (card_number)


def luhn_algorithm(card_number):

    # get every other digit
    luhn1_total = 0
    for i in range((len(card_number)-1),0,-2):      # -1 as an array, -2 for every other
        luhn1 = 0
        luhn1 = int(card_number[i-1]) * 2           # -1 to skip preceding & *2 for Luhn

        if luhn1 > 9:                               # if more than 1 digit in length
            last_digit = int(luhn1 % 10)            # get last digit
            first_digit = int(luhn1 / 10)           # get first digit
            luhn1_total += first_digit + last_digit # add to total
        else:
            luhn1_total += luhn1                    # add digits to total
    # print(f"total: {luhn1_total}")

    # get remaining digits
    luhn2_total = 0
    for i in range((len(card_number)-1),-1,-2):
        luhn2 = int(card_number[i])

        luhn2_total += luhn2

    final_total = luhn1_total + luhn2_total

    # print(f"total: {luhn2_total}")
    #print(f"Final total: {final_total}")

    # check if result ends in zero
    final_total = final_total % 10

    if final_total == 0:
        return(True)


def get_provider(card_number):

    first_two_digits = card_number[0] + card_number[1]

    if (card_number[0]) == "4" and (len(card_number) == 13 or len(card_number) == 16):
        print("VISA")

    #elif (card_number[0]) == "3" and ( (card_number[1]) == "4" or (card_number[1]) == "7" )\
    elif (first_two_digits) == "34" or (first_two_digits) == "37" and len(card_number) == 15:
        print("AMEX")

    elif (first_two_digits) == "51" or (first_two_digits) == "52" or (first_two_digits) == "53"\
                                    or (first_two_digits) == "54" or (first_two_digits) == "55"\
                                    and len(card_number) == 16:
        print("MASTERCARD")
    else:
        print("provider: INVALID")


# standard way to execute main
if __name__ == "__main__":
    main()