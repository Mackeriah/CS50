//Substitution Casear -  Owen FitzGerald July 2021

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
string cipherArray;
char alphabetArrayLower[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char alphabetArrayUpper[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};


int main(int argc, string commandLineText[])
{
    // check user entered correct number of arguments (e.g. string[0] is caesar and string[1] is cipher)
    if (argc == 2)
    {
        // Check whether exactly 26 characters entered by user
        int cipherLength = strlen(commandLineText[1]);
        if (cipherLength != 26)
        {
            printf("Error 1: Please enter 26 letter cipher - Usage: ./caesar key\n");
            return 1;
        }

        cipherArray = commandLineText[1];

        // Check whether user only entered alpha chars
        int validCipherChar = 0;
        for (int i = 0; i < cipherLength; i++)
        {
            if ((commandLineText[1][i] >= 97 && commandLineText[1][i] <= 122) || (commandLineText[1][i] >= 65 && commandLineText[1][i] <= 90))
            {
                // if current char is valid increase this variable
                validCipherChar += 1;
            }
            else
            {
                // exit and tell user incorrect usage
                printf("Error 2: Non-alpha characters entered - Usage: ./caesar key\n");
                i = cipherLength;  // I'm using this to terminate the for loop
                return 1;
            }
        }

        // Check that all letters are entered exactly once
        int letterIntTotal = 0;
        for (int i = 0; i < cipherLength; i++)
        {
            // convert each letter to lowercase so I can get decimal value
            char letterInteger = tolower(commandLineText[1][i]);
            letterIntTotal += letterInteger;
        }
        // decimal value of a-z is 2847
        if (letterIntTotal != 2847)
        {
            printf("Error 4: Ciper must include all letters in alphabet exactly once: ./caesar key\n");
            return 1;
        }
    }
    else  // user entered wrong number of arguments
    {
        printf("Error 3: Please enter 26 letter cipher: ./caesar key\n");
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

            if (islower(encryptedText[i]))
            {
                // find the current character in alpha array
                for (int j = 0; j < 26; j++)
                {
                    if (alphabetArrayLower[j] == encryptedText[i])
                    {
                        // printf("j %i ", j);
                        //printf("the letter is %c\n", alphabetArrayLower[j]);
                        // encryptedText[i] = alphabetArrayLower[j];
                        encryptedText[i] = tolower(cipherArray[j]);
                        j = 25;  // this is to exit the loop
                    }
                }

            }
            else if (isupper(encryptedText[i]))
            {
                // find the current character in alpha array
                for (int j = 0; j < 26; j++)
                {
                    if (alphabetArrayUpper[j] == encryptedText[i])
                    {
                        // printf("j %i ", j);
                        //printf("the letter is %c\n", alphabetArrayLower[j]);
                        // encryptedText[i] = alphabetArrayLower[j];
                        encryptedText[i] = toupper(cipherArray[j]);
                        j = 25;  // this is to exit the loop
                    }
                }
            }
        }
    }

    printf("ciphertext: %s", encryptedText);
    printf("\n");
    return 5;
}