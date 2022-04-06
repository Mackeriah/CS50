# //CS50 Readability - Owen FitzGerald 4/11/2021

from cs50 import get_string
from cs50 import get_int


def main():
    text = ask_user_for_text()
    global text_length
    text_length = len(text)

    # Call functions
    letters = count_number_of_letters(text)
    print(letters)

    words = count_number_of_words(text)
    print(words)

    sentences = count_number_of_sentences(text)
    print(sentences)

def count_number_of_letters(text):

    letters = 0
    for i in range(0, text_length, 1):
        if (text[i] >= 'a' and text[i] <= 'z') or (text[i] >= 'A' and text[i] <= 'Z'):
            letters += 1
    return(letters)


def count_number_of_words(text):

    words = 1
    for i in range(0, text_length, 1):
        if text[i] == ' ':
            words += 1
    return(words)


def count_number_of_sentences(text):

    sentences = 0
    for i in range(0, text_length, 1):
        if text[i] == '.' or text[i] == '?' or text[i] == '!':
            #if text[i +1] == ' ':
            sentences += 1
    return(sentences)



def ask_user_for_text():
    text = input("Text: ")
    return (text)

# standard way to execute main
if __name__ == "__main__":
    main()