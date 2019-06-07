#include <stdio.h>

typedef struct node node;
typedef struct tree tree;

//Left-child and Right-child representation
struct node
{
    node *left;
    node *right;
    int key;
};

//Left-child and Right-Sibling representation
struct node
{
    node *leftChild;
    node *rightSibling;
    int key;
};

struct tree
{
    node *root;
};


void printKeys(node*);

int main()
{
    /*
        TEST CODE
    */
}

//Recursive(Using Left-Right-Child)
void printKeys(node *r)
{
    if(r == NULL) {return;}
    else
    {
        printf("%d\n", r -> key);
        printKeys(r -> left);
        printKeys(r -> right);
    }
}

//non-recursive(Using a stack as an auxiliary data structure)
//Method left-root-right(inorder traversal)
//Using Left-Right-Child
void printKeys(tree *T)
{
    Stack<node *> stack; //Need to define stack
    push(stack, T -> root);

    node *x;
    while(TRUE)
    {
        x = pop(stack);
        if(x != NULL)
        {
            push(stack, x);
            push(stack, x -> left);
        }

        else
        {
            if(isEmpty(stack)) {break;}
            x = pop(stack);
            printf("%d\n", x -> key);
            push(stack, x -> right);
        }
        
    }
}

//Method to print all the keys using Left-child and Right-sibling
void printKeys(node *r)
{
    if(r != NULL) {printf("%d\n", r -> key);}

    if(r -> leftChild) {printKeys(r -> leftChild);}

    if(r -> rightSibling) {printKeys(r -> rightSibling);}
}