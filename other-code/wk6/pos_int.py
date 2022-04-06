
def get_positive_int():
    while True:
        n = input("Please enter positive integer: ")
        n = int(n)
        if n > 0:
            print(f"{n}")
            break
    return n


get_positive_int()