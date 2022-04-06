#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// create struct
typedef struct node
{
    int number;
    struct node* next;
}
node;

// declare global variables
node *listHEAD = NULL;  // create linked list 'head'
int userInt;

// declare prototypes
void getInt();
int insertNodeAtStart(int nodeValue);
int freeMemory();
void printList();
bool findValueInList(node *marker, int nodeValue);


/* TO DO
DONE: create a linked list (handled with struct and global variable)
DONE: create a function to create a node at the start of the list
DONE: function to search for a value
DONE: function to add a node to end of list (NODE 9)
IGNORED:  do this? function to add a node within a list.
Why was the last ignored?  It occurs to me from listing to another video from Doug, that
it's simplest to always add to the front of a linked list, which is my insertNodeAtStart function
because by using this you just use the same code each time.  It doesn't matter.  I don't
think you even want to be sorting a linked list anyway, so therefore why would you even want
to enter another node at a point other than at the front.  The other data you can
already search for and find, so it doesn't matter where it is.
TO DO: delete an item from a linked list. I think this is worth doing.

*/


int main(void)
{
    getInt();

    /*  Each time you use malloc it will allocate your new memory as requested.
        even if you use the same variable.  Malloc doesn't know or care, it just allocates more memory.
        If you don't keep track of this address then you'll leak memory, as once you use the same
        variable again, you will lose track of where mallocs previous address allocation was.  But with
        linked listHEADs, the whole point is that we have the head point to the first node, and that node
        point to the next node etc.  So we know all address locations.
    */

    getInt();
    getInt();
    getInt();

    printList();



    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    n->number = 9;
    n->next = NULL;
    listHEAD->next->next->next->next = n;


    printf("\n");
    printList();


    findValueInList(listHEAD, 7);


    freeMemory();

}

void getInt()
{
    printf("Enter value for the node: ");
    scanf("%i", &userInt);
    insertNodeAtStart(userInt);
}

int insertNodeAtStart(int nodeValue)
{
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    n->number = nodeValue;  // set this nodes number value from user integer
    n->next = listHEAD;  // point at the listHEAD (which is itself pointing at the current 'first' node)
    listHEAD = n; // now we can safely repoint the listHEAD at the new node, which means this new node is in 'first' place
    return 0;

    /*
    - HEAD->NODE1
    Each time you insert a new node, you initially point the new node.next at HEAD
    - NODE2->HEAD
    BUT HEAD is itself pointing at the current first node
    - NODE2->HEAD->NODE1
    so that means that the NEWLY created node is also pointing at the current first node (both HEAD and the new node are pointing at the same memory)
    you then change HEAD to point at the NEW node
    - HEAD->NODE2->NODE1
    this new node.next is itself left pointing at the original node
    but HEAD is now pointing at the new node instead
    END: HEAD->NODE2->NODE1
    */

}


bool findValueInList(node *marker, int nodeValue)
{
    for (marker = listHEAD; marker != NULL; marker = marker->next)
    {
        if (marker->number == nodeValue)
        {
            printf("found\n");
            return 1;
        }
    }
    printf("NOT found\n");
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
        printf("%i\n", tmp->number);
    }
}

