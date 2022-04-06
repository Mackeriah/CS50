#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define TABLE_SIZE 10
#define MAX_NAME 256

typedef struct node
{
    int age;
    char name[MAX_NAME];
    // add other stuff later if required
    struct node *next;
}
node;

// create our hash table, which is essentially an array of pointers
node *hash_table[TABLE_SIZE];

// declare global variables
int getName2();
int numberOfUsers = 3;

// declare prototypes
void getNodeString();
int insertNode();
int freeMemory();
void printList();
bool findValueInList(node *marker, int nodeValue);



int main(void)
{

    hash_table[0] = NULL;

    for (int i = 0; i < (numberOfUsers); i++)
    {
        insertNode();
    }

    printList();
    freeMemory();
}

// inserts a new node at the start
int insertNode()
{
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }

    // ask user for string
    char userStr[MAX_NAME];
    printf("Please enter name (20 chars max): ");
    scanf("%[^\n]%*c", userStr);

    // ask user for integer
    int userInt;
    printf("Enter age: ");
    scanf("%i", &userInt);
    getchar();  // this is a bizarre workaround to ensure that the carriage return (newline) when user presses enter is ignored, otherwise it screws up the next scanf

    n->age = userInt;
    strcpy(n->name, userStr);  // this is the only way I've found of getting a user entered string into the node
    n->next = hash_table[0];
    hash_table[0] = n;
    return 0;
}


int freeMemory()
{
    // return all the memory
    while (hash_table[0] != NULL)  // while hash_table[0] specifically is at pointing at a node (would presumably need to include all array elements eventually)
    {
        node *tmp = hash_table[0]->next; // create a temp node pointing at the next 'element' for the node AFTER hash_table[0]
        free(hash_table[0]); // return memory that hash_table[0] was pointing at
        hash_table[0] = tmp;  // repoint hash_table[0] at the address for the node after hash_table[0]
    }
    return 0;
}

void printList()
{
    for (node *tmp = hash_table[0]; tmp != NULL; tmp = tmp->next)
    {
        printf("%i %s\n", tmp->age, tmp->name);
    }

    for (node *tmp = hash_table[1]; tmp != NULL; tmp = tmp->next)
    {
        printf("%i %s\n", tmp->age, tmp->name);
    }
}


// void getNodeString()
// {
//     printf("Please enter name (20 chars max): ");
//     scanf("%[^\n]%*c", userStr);
//     insertNode(userStr);
// }

/* keep this so you can reuse the logic to check if string too long */
// char getName2()
// {
//     char str[20];
//     printf("Please enter name (20 chars max): ");
//     scanf("%[^\n]%*c", str);
//     printf("%s\n", str);
//     return str;

//     // if (strlen(str) > 20)
//     // {
//     //     printf("Name too long\n");
//     //     return 1;
//     // }
//     // else
//     // {
//     //     printf("strlen line: Name: %s\n", str);
//     //     insertNode(str);
//     // }
//     //return 0;
// }


// bool findValueInList(node *marker, int nodeValue)
// {
//     for (marker = listHEAD; marker != NULL; marker = marker->next)
//     {
//         if (marker->age == nodeValue)
//         {
//             printf("Looked for and found %i\n", nodeValue);
//             return 1;
//         }
//     }
//     printf("NOT found\n");
//     return 0;
// }
