#include <stdio.h>

struct node
{
    node *parent;
    node *left;
    node *right;
    int key;
} node;

struct tree
{
    node *root;
} tree;

//Method to print all tree keys with inOrder traversal
void inOrderPrint(node *);

int main()
{
    /*
        TEST CODE
     */
}

//Depth-first Search
//Recursive Method inOrder
void inOrderPrint(node *r)
{
    if(r == NULL) {return;}
    
    inOrderPrint(r -> left);
    printf("%d\n", r -> key);
    inOrderPrint(r -> right);
}

//Recursive Method postOrder
void postOrderPrint(node *r)
{
    if(r == NULL) {return;}

    postOrderPrint(r -> left);
    postOrderPrint(r -> right);
    printf("%d\n", r -> key);
}

//Recursive Method preOrder
void preOrderPrint(node *r)
{
    if(r == NULL) {return;}

    printf("%d\n", r -> key);
    preOrderPrint(r -> left);
    preOrderPrint(r -> right);
}

//Non-Recursive Method using stack as an auxiliary data structure
void inOrderPrint(tree *T)
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

//Another Non-Recursive Method
void inOrderPrint(tree *T)
{
    Stack<node *> stack;
    node *x = T -> root;

    while(x != NULL || !isEmpty(stack))
    {
        while(x != NULL)
        {
            push(stack, x);
            x = x -> left;
        }

        x = pop(stack);
        printf("%d\n", x -> key);
        x = x -> right;
    }
}

//Method for Bredth-first Search
void bredthFirstPrint(tree *T)
{
    node *r = T -> root;
    if(r == NULL) {return;}

    Queue *q = newQueue(); //Need to define queue

    enqueue(q, r);
    while(!isEmpty(q))
    {
        r = dequeue(q);
        if(r -> left) {enqueue(q, r -> left);}
        if(r -> right) {enqueue(q, r -> right);}
        printf("%d\n", r -> element);
    }
}

//Recursive method to search for a key in a tree
node *treeSearch(node *x, int k)
{
    if(x == NULL || x -> key == k) {return x;}

    if x -> key > k {return treeSearch(x -> left, k);}
    else {return treeSearch(x -> right, k);}
}

//Iterative method to search for a key in a tree
node *treeSearch2(tree *T, int k)
{
    node *r = T -> root;
    
    while(r != NULL && r -> key != k)
    {
        if(k < r -> key) {r = r -> left;}
        else {r = r -> right;}
    }

    return r;
}

//Iterative method to find the minimum value in a tree
node *treeMinimum(node *x)
{
    while(x -> left != NULL) {x = x -> left;}

    return x;
}

//Iterative method to find the maximum value in a tree
node *treeMaximum(node *x)
{
    while(x -> right != NULL) {x = x -> right;}

    return x;
}

//Recursive method to find the minimum value in a tree
node *treeMinimum(node *x)
{
    if(x -> left != NULL) {return treeMinimum(x -> left);}

    return x;
}

//Recursive method to find the maximum value in a tree
node *treeMaximum(node *x)
{
    if(x -> right != NULL) {return treeMaximum(x -> right);}

    return x;
}

//Method to find the sucessor of any node
node *findSucessor(node *x)
{
    if(x -> right != NULL) {return treeMinimum(x -> right);}

    node *y = x -> parent;
    while (y != NULL && x = y -> right)
    {
        x = y;
        y = y -> parent;
    }

    return y;
}

//Method to find the predecessor of any node
node *findPredecessor(node *x)
{
    if(x -> left != NULL) {return treeMaximum(x -> left);}

    node *y = x -> parent;
    while(y != NULL && x = y -> left)
    {
        x = y;
        y = y -> parent;
    }

    return y;
}

//Iterative method to insert  a node
void treeInsert(tree *T, node *z)
{
    node *y;
    node *x = T -> root;
    
    while(x != NULL)
    {
        y = x;
        if(z -> key < x -> key) {x = x -> left;}
        else {x = x -> right;}
    }

    z -> parent = y;
    if(y == NULL) {T.root = z;}
    else if(z -> key < y -> key) {y -> left = z;}
    else {y -> right = z;}
}

//Recursive method to insert a node
void treeInsert(node *z, node *x)
{
    if(z == NULL) {z = x;}

    else
    {
        if(x -> key < z -> key) {treeInsert(z -> left, x);}

        else {treeInsert(z -> right, x);}
    }
}

//Method to substitute a sub-tree rooted on u for a tree rooted on v
void transplant(tree *T, node *u, node *v)
{
    if(u -> parent == NULL) {T -> root = v;}

    else if(u == (u -> parent) -> left) {(u -> parent) -> left = v;}

    else {(u -> parent) -> right = v;}

    if(v != NULL) {v -> parent = u -> parent;}
}

//Method to delete a node
void treeDelete(tree *T, node *z)
{
    if(z -> left == NULL) {transplant(T,z, z -> right);}

    else if(z -> right == NULL) {transplant(T, z, z -> left);}

    else
    {
        node *y = treeMinimum(z -> right);

        if(y -> parent != z)
        {
            transplant(T, y, y -> right);
            y -> right = z -> right;
            (y -> right) -> parent = y;
        }

        transplant(T, z, y);
        y -> left = z -> left;
        (y -> left) -> parent = y;
    }
}