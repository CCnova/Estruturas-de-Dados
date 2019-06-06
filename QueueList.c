//Queue implementation using linked list
#include <stdlib.h>

typedef struct element* Element;
typedef struct linkedList* lList;
typedef enum {FALSE, TRUE} bool;

struct element
{
    Element next;
    int key;
};

struct linkedList
{
    Element front;
    Element back;
    int size;
    int maxSize;
};

bool enqueue(lList, Element);
Element dequeue(lList);
lList newQueue(int);
bool isEmpty(lList);
bool isFull(lList);

int main()
{
    /*
        TEST CODE
    */

   return 0;
}

lList newQueue(int max)
{
    lList l = malloc(sizeof(struct linkedList));
    l -> front = NULL;
    l ->back = NULL;
    l -> size = 0;
    l -> maxSize = max;

    return l;
}

Element dequeue(lList l)
{
    if(isEmpty(l)) {return NULL;}

    Element e = l -> front;
    l -> front = (l -> front) -> next;

    l -> size--;

    if(isEmpty(l)) {l -> front = l -> back = NULL;}

    return e;
}

bool enqueue(lList l, Element e)
{
    if(isFull(l)) {return FALSE;}

    if(isEmpty(l)) {l -> front = e;}
    else {(l -> back) -> next = e;}

    l -> back = e;
    l -> size++;

    return TRUE;
}

bool isEmpty(lList l)
{
    return l -> size == 0;
}

bool isFull(lList l)
{
    return l -> size == l -> maxSize;
}
