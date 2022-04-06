//CS50 Casear -  Owen FitzGerald July 2021

#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Decalare fucntions
int encryptText();

// Decalare global variables
string textToEncrypt;
int cipherInteger;
string encryptedText;


int main(int argc, string commandLineText[])
{
    // check user entered correct number of arguments (e.g. string[0] is caesar and string[1] is cipher)
    if (argc == 2)
    {
        int cipherLength = strlen(commandLineText[1]);
        int validCipherChar = 0;
        for (int i = 0; i < cipherLength; i++)
        {
            // user entered integer between 0 to 9 (ASCII 48 - 57) for the 2nd string in this array
            if (commandLineText[1][i] >= 48 && commandLineText[1][i] <= 57)
            {
                // if current char is valid increase this variable
                validCipherChar += 1;
            }
            else
            {
                // exit and tell user incorrect usage
                printf("Usage: ./caesar key\n");
                i = cipherLength;  // I'm using this to terminate the for loop
                return 1;
            }
        }
        // if each cipher character was an integer, these will match
        if (validCipherChar == cipherLength)
        {
            // convert cipher into an int
            cipherInteger = atoi(commandLineText[1]);
        }
    }
    else  // user entered wrong number of arguments
    {
        printf("Error: Single integer key required: ./caesar key\n");
        return 1;
    }

    // this is purely to meet the following requirement "Your program should then exit by returning 0 from main."
    // so I made encryptText an int function so it can return a value, which I've arbitrarily made 5 here.
    // good commenting past Owen, as I had no fucking idea what this was just a day or 2 later!
    int a = encryptText();
    if (a == 5)
    {
        // printf("All OK\n");
        return 0;
    }
}

int encryptText()
{
    // ask user to enter text to be encrypted
    textToEncrypt = get_string("plaintext:  ");
    // I originally thought this made no sense, but actually it means I always have the original and the encrypted
    encryptedText = textToEncrypt;

    // get length of user text so we know how many times to loop through
    int encryptedTextLength = strlen(encryptedText);
    for (int i = 0; i < encryptedTextLength; i++)
    {
        // if it ain't a-z or A-Z, we don't care
        if ((encryptedText[i] >= 'a' && encryptedText[i] <= 'z') || (encryptedText[i] >= 'A' && encryptedText[i] <= 'Z'))
        {
            // this is where the magic happens: for each letter add 1 until you've reached the ciper value the user originally entered
            // but if adding +1 has pushed the letter beyond z or Z, loop around so the letter is a or A
            for (int j = 0; j < cipherInteger; j++)
            {
                if (islower(encryptedText[i]))
                {
                    encryptedText[i] += 1;
                    if (encryptedText[i] > 'z')
                    {
                        encryptedText[i] = 'a';
                    }
                }
                else if (isupper(encryptedText[i]))
                {
                    encryptedText[i] += 1;
                    if (encryptedText[i] > 'Z')
                    {
                        encryptedText[i] = 'A';
                    }
                }
            }
        }
    }

    printf("ciphertext: %s", encryptedText);
    printf("\n");
    return 5;
}