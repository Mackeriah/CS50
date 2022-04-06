#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// create struct
typedef struct node
{
    char *name;
    struct node* next;
}
node;

// declare global variables
node *listHEAD = NULL;  // create linked list 'head'
char userStr[20];

// declare prototypes
void getNodeInt();
int insertNodeStart(char *nodeValue);
int freeMemory();
void printList();
int linkedList();
int linkedList2();

int main(void)
{

    linkedList();
    linkedList2();

    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    n->name = "Immy";
    n->next = listHEAD;  // point at the listHEAD which is itself pointing at the current 'first' node
    listHEAD = n; // now we can safely repoint the listHEAD at the new node

    printList();

    freeMemory();
}


int linkedList()
{
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    n->name = "Owen";
    n->next = listHEAD;  // point at the listHEAD which is itself pointing at the current 'first' node
    listHEAD = n; // now we can safely repoint the listHEAD at the new node
    return 0;
}

int linkedList2()
{
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    n->name = "Carly";
    n->next = listHEAD;  // point at the listHEAD which is itself pointing at the current 'first' node
    listHEAD = n; // now we can safely repoint the listHEAD at the new node
    return 0;
}


int freeMemory()
{
    // return all the memory
    while (listHEAD != NULL)  // while listHEAD is at pointing at a node
    {
        node *tmp = listHEAD->next; // create a temp node pointing at the next 'element' for the node AFTER listHEAD
        free(listHEAD); // return memory that listHEAD was pointing at
        listHEAD = tmp;  // repoint listHEAD at the address for the node after listHEAD
    }
    return 0;
}

void printList()
{
    // print using for loop
    /*  give me a temporary pointer to a node called tmp and initialise it to whatever is the beginning of listHEAD
        keep running this for loop as long as tmp does not equal NULL (e.g. we reached the last node)
        update tmp pointer to be the value of the value of the tmp pointers next field is
    */
    for (node *tmp = listHEAD; tmp != NULL; tmp = tmp->next)
    {
        printf("%s\n", tmp->name);
    }
}

