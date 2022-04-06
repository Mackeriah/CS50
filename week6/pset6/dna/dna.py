# DNA (AKA: finding the murderer!) - Owen FitzGerald 8/11/2021

import sys
from re import search
import itertools
from csv import reader, DictReader


def main():

    # initilise here so I can access elsewhere
    STR_names = [""]

    # Ensure correct usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")
    csv_path = sys.argv[1]
    txt_path = sys.argv[2]

    # store STR names from suspect CSV (but ignore 'name' column itself)
    with open(csv_path, "r") as csvfile:
        CSV_reader = DictReader(csvfile, delimiter=',')

        # get CSV length
        CSV_length = len(CSV_reader.fieldnames)-1  # -1 as we will skip first element

        # store all STR headings (excluding first as it's not an STR)
        STR_names = [""] * CSV_length
        for i in range(CSV_length):
            STR_names[i] += (CSV_reader.fieldnames[i+1])  # +1 to skip first element

    # open file for TXT and create list
    with open(txt_path, "r") as txtfile:
        DNA_textfile = txtfile.read()

    # Look through DNA_textfile to find consecutive STRs
    STR_total = []
    for i in range(1, len(CSV_reader.fieldnames)):  # get number of fields (name, AGATC etc) start at 1 to skip names
        STR_name = CSV_reader.fieldnames[i]              # set STR as first fieldname
        STR_total.append(0)                         # reset current i element for STR_total to zero

    # Look for consecutive STRs in DNA_textfile
        for j in range(0, len(DNA_textfile), 1):
            count = 0
            # check if text at location j + length of current STR includes the current STR
            if DNA_textfile[j:(j + len(STR_name))] == STR_name:
                k = 0
                # if it does then check again but this time increment count and add k each time
                # to check whether another STR is immediately after it
                while DNA_textfile[(j + k):
                                   # add length to j+k to check for another STR immedaitely following
                                   (j + k + len(STR_name))] == STR_name:
                    count += 1
                    # increment this so we can keep checking beyond the most recently found STR
                    k += len(STR_name)

                # Update max count if count exceeds it
                if count > STR_total[i - 1]:        # -1 as we are always one ahead
                    STR_total[i - 1] = count

    # print(f"Total consecutive STRs: {STR_total}")

    '''
    # old code that counted total not consecutive!!
    # count STR in DNA sequence from text file of murder weapon
    with open(txt_path, "r") as file:
        murder_weapon_sample = file.read()
        length = len(murder_weapon_sample)
        STR_names_length = len(STR_names)       # count how many in STR_names
        weapon_count = [0] * STR_names_length
        for i in range(STR_names_length):
            substring = STR_names[i]
            weapon_count[i] = (murder_weapon_sample.count(substring))
        # print(f"(Mine) weapon count{weapon_count}")
    '''

    # the below is creating a new list consisting of each STR and it's total count from murder weapon
    temp1 = [""]
    temp2 = [""]
    weapon_DNA = []  # weapon_DNA is a list
    # for i in range(STR_names_length):
    for i in range(len(STR_total)):
        temp1[0] += STR_names[i]
        #temp2[0] += str(weapon_count[i])
        temp2[0] += str(STR_total[i])
        weapon_DNA += list(itertools.chain(temp1, temp2))
        temp1[0] = ""
        temp2[0] = ""
    # print(f"Murder weapon DNA results: {weapon_DNA}")

    # store weapon STRs in a new list
    half_weapon_length = int((len(weapon_DNA) / 2))     # half because we have 2 for each element
    j = 0
    weapon_STR = [""] * half_weapon_length
    for i in range(0, len(weapon_DNA), 2):
        weapon_STR[j] += (weapon_DNA[i])
        j += 1
    # print(f"STR names: {weapon_STR}")

    # store weapon values in a new list
    half_weapon_length = int((len(weapon_DNA) / 2))     # half because we have 2 for each element
    j = 0
    weapon_value = [""] * half_weapon_length
    for i in range(1, len(weapon_DNA), 2):
        weapon_value[j] += (weapon_DNA[i])
        j += 1
    # print(f"STR values: {weapon_value}")

    # compare suspect DNA with murder weapon DNA
    with open(csv_path, "r") as file:
        suspect_reader = DictReader(file)
        for STR in suspect_reader:
            tally = 0
            j = 1
            # print(f"x:{half_weapon_length}")
            for i in range(half_weapon_length):     # which is 3 for small.csv
                if STR[weapon_STR[i]] == weapon_value[i]:
                    tally += 1
            # exit once we've counted all types of STR
            if tally == half_weapon_length:
                print(STR["name"])
                match = "true"
                exit()
            else:
                match = "false"

    if match == "false":
        print("No match")


if __name__ == "__main__":
    main()
