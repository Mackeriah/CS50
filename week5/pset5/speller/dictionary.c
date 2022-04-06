// Dictionary part of Speller - Owen FitzGerald CS50 October 2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <strings.h>
#include "dictionary.h"


// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Prototypes
void initialise_hash_table();
bool insert_word();
node *hash_table_lookup (const char *word);
void convert_to_lower();
//void print_table();

// Global variables
int counter = 0;
bool load_complete = false;
char nextWord[LENGTH+1] = "";
char lowerCaseWord[LENGTH+1];

// Number of buckets in hash table
const unsigned int TABLE_SIZE = 256;


// Create hash table
node *table[TABLE_SIZE];


// Initialise hash table
void initialise_hash_table()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        table[i] = NULL;
    }
}


// Loads dictionary into memory one word at a time
bool load(const char *dictionary)
{
    initialise_hash_table();

    // open dictionary file for reading
    FILE *dictionary_file = fopen(dictionary, "r");
    if (dictionary_file == NULL)
    {
        printf("Could not open %s.\n", dictionary);
        unload();
        return 1;
    }

    // get next word from dictionary (+2 is ONLY to cater for longest word)
    while(fgets(nextWord, LENGTH+2, dictionary_file))
    {
        // used for size function to keep track of words loaded
        counter++;

        // get length of string
        int length = strlen(nextWord);

        // remove any trailing newline
        if (nextWord[length-1] == '\n')
            nextWord[length-1] = 0;

        insert_word();
    }

    //print_table();  // testing only

    // used for size function to know when file loaded (probably a better way!)
    load_complete = true;
    fclose(dictionary_file);
    return true;
}


// insert current dictionary word into specific hash table location/bucket
bool insert_word()
{
    unsigned int index = hash(nextWord); // get hash for word
    node *n = malloc(sizeof(node));      // create new node n
    if (n == NULL)
        return 1;

    strcpy(n->word, nextWord); // copy nextword (for dictionary) in to n->word
    n->next = table[index];    // point node n->next at head of the hash/bucket index
    table[index] = n;          // point head at new node thus making it the first node in list
    return true;
}


// Generates hash value for word (hash function based on Jacob Sorber example)
unsigned int hash(const char *wordToHash)
{
    int wordLength = strlen(wordToHash);
    unsigned int hash_value = 0;
    for (int i = 0; i < wordLength; i++)
    {
        hash_value += wordToHash[i];
        hash_value = hash_value % TABLE_SIZE;
    }
    return hash_value;
}


// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    if (load_complete == true)
        return counter;
    else
        return 0;
}


// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // create tmp node
    node *tmp = hash_table_lookup(word);
    if (tmp == NULL)
    {
        // printf("Not found!\n");
        return false;
    }
    else
    {
        // printf("Found %s.\n", tmp->word);
        return true;
    }
}


node *hash_table_lookup(const char *word)
{
    // we do this because dictionary words are in lowercase
    convert_to_lower(word);

    //generate hash for word so we knonw which location/bucket to look in
    unsigned int index = hash(lowerCaseWord);

    // create tmp node at start of appropriate location/bucket
    node *tmp = table[index];

    // tmp traverses list until tmp->next is NULL (list end) tmp->word matches word
    while (tmp != NULL && strcasecmp(tmp->word, lowerCaseWord) != 0)
    {
        // point tmp at next node
        tmp = tmp->next;
    }
    return tmp;  // will either be NULL (not found) or a value (found)
}


// convert text file word to lowercase (dictionary words are lowercase already)
void convert_to_lower(const char *wordtolowercase)
{
    // wipe tmp word array before use
    for (int i = 0; i < LENGTH+1; i++)
        lowerCaseWord[i] = 0;

    // convert word to lowercase and store in different variable
    for(int i = 0; wordtolowercase[i]; i++)
    {
        lowerCaseWord[i] = tolower(wordtolowercase[i]);
    }
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        while (table[i] != NULL)
        {
            node *tmp = table[i]->next; // create a temp node pointing at the next 'element' for the node AFTER table[i]
            free(table[i]); // return memory that table[i] was pointing at
            table[i] = tmp;  // repoint table[i] at the address for the node after table[i]
        }
    }
    return true;
}


// void print_table()
// {
//     printf("Start\n");
//     for (int i = 0; i < TABLE_SIZE; i++)
//     {
//         if (table[i] == NULL)
//             printf("\t%i\t---\n", i);
//         else
//         {
//             printf("\t%i\t",i);
//             node *tmp = table[i];
//             while (tmp != NULL)
//             {
//                 // get length of string
//                 int length = strlen(tmp->word);

//                 // // remove any trailing newline
//                 if (tmp->word[length-1] == '\n')
//                     tmp->word[length-1] = 0;

//                 printf("%s - ", tmp->word);
//                 tmp = tmp -> next;
//             }
//             printf("\n");
//         }
//     }
//     printf("End\n");
// }