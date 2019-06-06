//A double linked list with a sentinel

#include <stdio.h>

typedef struct linkledList* lList;
typedef struct element* Element;

struct linkedList
{
    Element nil;
};

struct element
{
    Element next;
    Element prev;
    int key;
};

void insert(lList, Element);
void delete(lList, Element);
Element search(lList, int);

int main()
{

    return 0;
}

void insert(lList l, Element e)
{
    e -> neet = (l -> nil) -> neet;
    e -> prev = l -> nil;
    (l -> nil) -> neet = e;
    ((l -> nil) -> neet) -> prev = e;
}

void delete(lList l, Element e)
{
    (e -> prev) -> next = e -> next;
    (e -> next) -> prev = e -> prev;
}

Element search(lList l, int x)
{
    Element e = (l -> nil) -> next;

    while(e != l -> nil && e ->  key != x) {e = e -> next;}

    return e;
}