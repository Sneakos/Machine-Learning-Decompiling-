#include <stdio.h>
#include <stdlib.h>

struct stacks{
        int val;
        struct stacks *next;
};

typedef struct stacks *stack;

stack makeStack(int v){
        stack start = NULL;

        start = malloc(sizeof(stack));
        start->val = v;
        start->next = NULL;
        return start;
}

stack push(stack start, int v){
    stack tmp = makeStack(v);

    tmp->next = start;
    return tmp;
}

stack pop(stack start){
    stack tmp;

    tmp = start;
    start = start->next;
    free(tmp);
    return start;
}

void print_stack(stack start){
    stack mov;
    mov = start;
    printf("__________\n");
    while(mov != NULL){
        printf("%5d\n",mov->val);
        mov = mov->next;
    }
    printf("__________\n");
}

int isEmpty(stack start){
    if(start == NULL)
        return 1;
    else
        return 0;
}

int main(){
}

---------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

 // New name for types. make names more meaningful/readable.
typedef struct elem_type node; // node is the new name
typedef node *link;  // New name for node, a future link.

struct  elem_type
{
        int data;
        link next;
		link back;
};

struct header_type
{
        link top;
};

typedef struct header_type *stack;
// list as a data type


link makeNode( int x )
{
        link b;

        b = malloc( sizeof( node )  );
        b->data = x;
        b->next = NULL;
		b->back = NULL;
        return b;

}




list makeList()
{
        stack newL;

        newL = malloc( sizeof( struct header_type ));
        newL->top = NULL;

        return newL;

        //you allocate space for the beginning of the list. Its a pointer to a header node, its a pointer to a box of pointers.
}

int isEmpty( list L )
{
	if( L->top == NULL )
		return 1;
	else
		return 0;
}


void push( list L, int num )
{
    link b;
    b = makeNode( num );
    if( isEmpty( L ) == 1 ){
        L->top = b;
    } else {
        L->top->next = b;
		b->back = L->top;
        L->top = b;
    }

}

void pop( list L )
{
	link top, junk;

    top = L->top;
    junk = top;
    top = top->back;
    free( junk );
    L->top = top;

}

void printList( list L )
{
        link mov;
        printf("List: ");
        mov = L->top;

        while ( mov != NULL )
        {
                printf("%2d ", mov->data );
		mov=mov->back;
        }
        printf("\n");
}


int main()
{

        return 0;
}

