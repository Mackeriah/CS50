//read words in file

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *file;  // create pointer of type FILE using the file name 'file'
int counter = 0;

#define LENGTH 45


// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Create hash table
node *table[N];

// Initialise hash table
void initialise_hash_table()
{
for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }
}

void print_table()
{
    printf("Start\n");
    for (int i = 0; i < N; i++)
    {
        if (table[i] == NULL)
        {
            printf("\t%i\t---\n", i);
        }
        else
        {
            printf("\t%i\t%s\t \n", i, table[i]->word);
        }
    }
    printf("End\n");
}

// inserts a new node at the start
int insertNode()
{
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }

    //char userStr[LENGTH];
    char *userStr = "Owen";
    strcpy(n->word, userStr);
    n->next = table[0];
    table[0] = n;
    return 0;
}

int insertNode2()
{
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }

    //char userStr[LENGTH];
    char *userStr = "Carly";
    strcpy(n->word, userStr);
    n->next = table[1];
    table[1] = n;
    return 0;
}



int main()
{

initialise_hash_table();
print_table();



    // // open file
    // file = fopen("dictionaries/small", "r");
    // if (file == NULL)
    // {
    //     printf("Could not open file\n");
    //     exit(0);
    // }
    // printf("Dictionary opened\n");


    // char nextWord;
    // char str[10];
    // while(fgets(str, 20, file))
    // {
    //     printf("%s", str);
    //     counter++;
    // }
    // printf("\n");

    // printf("Total worlds in file: %i\n", counter);

    insertNode();
    insertNode2();
    // printf("table[%s]\n", table[1]->word);
    // printf("table[%p]\n", table[1]->next);

    print_table();

}