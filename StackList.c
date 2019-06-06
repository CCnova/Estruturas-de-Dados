//A stack implemented with a singly linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct linkedList* lList;
typedef struct element* Element;
typedef enum {FALSE, TRUE} bool;

struct element
{
    Element next;
    int key;
};

struct linkedList
{
    Element head;
    int size;
};

bool push(lList, Element);
Element pop(lList);
lList newList(void);

int main()
{
    /*
        Test Code

    */

   return 0;
}

lList newList()
{
    lList l = malloc(sizeof(struct linkedList));
    l -> head = NULL;
    l -> size = 0;

    return l;
}

bool push(lList l, Element e)
{
    e -> next = l -> head;
    l -> head = e;

    l -> size++;

    return TRUE;
}

Element pop(lList l)
{
    if(l -> head == NULL) {return NULL;}

    Element e = l -> head;

    l -> head = (l -> head) -> next;

    l -> size--;

    return e;
}
