//CS50 Readability -  Owen FitzGerald June 2021

#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Decalare fucntions
float count_number_of_sentences(string text);
float count_number_of_words(string text);
float count_number_of_letters(string text);

// Decalare global variables
float sentences;
float words;
int textLength;
float letters;

int main(void)
{
    // Get user input
    string text = get_string("Text: ");
    textLength = strlen(text);

    // Call functions
    count_number_of_letters(text);
    count_number_of_words(text);
    count_number_of_sentences(text);

    // Calculate averages and apply to Coleman-Liau formula
    float averageLetters = letters / words * 100;
    float averageSentences = sentences / words * 100;
    float colemanLiau = 0.0588 * averageLetters - 0.296 * averageSentences - 15.8;

    if (colemanLiau > 16)
    {
        printf("Grade 16+\n");
    }
    else if (colemanLiau < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %.0f\n", colemanLiau);
    }

    // printf("%f letter(s)\n", letters);
    // printf("%f word(s)\n", words);
    // printf("%f sentence(s)\n", sentences);
    // printf("String length: %i\n", textLength);
    // printf("%.2f average letters\n", averageLetters);
    // printf("%.2f average sentences\n", averageSentences);

}

float count_number_of_sentences(string text)
{
    sentences = 1;
    for (int i = 0; i < textLength; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            if (isblank(text[i + 1]))
            {
                sentences += 1;
            }
        }
    }
    return sentences;
}

float count_number_of_words(string text)
{
    words = 1;
    for (int i = 0; i < textLength; i++)
    {
        if (isblank(text[i]))
        {
            words += 1;
        }
    }
    return words;
}

float count_number_of_letters(string text)
{
    letters = 0;
    for (int i = 0; i < textLength; i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letters += 1;
        }
    }
    return letters;
}