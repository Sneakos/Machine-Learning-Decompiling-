
// Linked List program 3

// Create a Header Node to represent the linked list
// Renamed many items to keep it interesting and fresh

// Functions
//  List functions
//    - create a new list
//    - allocate a node
//    - insert node at front
//    - print list
//    - find length of list
//  Utility functions
//    - allocate a node

#include <stdio.h>
#include <stdlib.h>

typedef struct elem_type node; //typedef makes a new name for a type, doesn't create a type
//structure elem_type is nown as node
typedef node *link;

struct  elem_type{
        int data;
        link next; //pointer to a node type
};

struct header_type{
        link first;
        link last;
        int  len;
};

typedef struct header_type *list;
//list points to a header node


link makeNode( int x )
{
        link b;

        b = malloc( sizeof( node )  );
        b->data = x;
        b->next = NULL;
        return b;
}


int listLength( list L )
{
        int len = 0;
        link mov;
        mov = L->first;
        while ( mov != NULL )
        {
                len++;
                mov = mov->next;
        }

        return len;
}


void printList( list L )
{
        link mov;
        printf("List: ");
        mov = L->first;
        while ( mov != NULL )
        {
                printf("%2d ", mov->data );
                mov = mov->next;
        }
        printf("\n");
}

void insertFront( list L, int num ){
        link b;
        b =  makeNode( num );
        b->next = L->first;
        L->first = b;
}

list makeList(){
        list newL;

        newL = malloc( sizeof(struct header_type));
        newL->first = NULL;
        newL->last = NULL;
        newL->len = 0;

        return newL;
}

int main(){
        list AList;//pointer to header node
        int k, x;

        AList = makeList(); //called one time to make the header

        insertFront( AList, 12 );
        printList( AList );
        printf("Len %d\n", listLength( AList ) );

//a) Insert 5 random values (under 100)

        for ( k = 0; k < 5; ++k )
        {
                x = rand() % 100;
                printf("Adding %d\n", x);
                insertFront( AList, x );
        }

//b) Print the list

        printList( AList );

        return 0;
}
