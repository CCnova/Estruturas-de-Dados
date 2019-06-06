//A double linked list without a sentinel
#include <stdio.h>

typedef struct element *Element;
typedef struct linkedList *linkList;

struct element
{
    Element next;
    Element prev;
    int key;
};


struct linkedList
{
    Element head;
    Element tail;
};

Element search(linkList, int);
void insert(linkList, Element);
void delete(linkList, Element);

int main()
{

}

Element search(linkList l, int x)
{
    Element aux = l -> head;

    while(aux != NULL && aux -> key != x)
    {
        aux = aux + 1;
    }

    return aux;
}

void insert(linkList l, Element x)
{
    x -> next = l -> head;

    if(l -> head != NULL) {(l -> head) -> prev = x;}
    l -> head = x;
    x -> prev = NULL;
}

void delete(linkList l, Element x)
{
    if(x -> prev != NULL)
    {
        (x -> prev) -> next = x -> next;
        (x -> next) -> prev = x -> prev;
    }
    
    else {l -> head = x -> next;}

}