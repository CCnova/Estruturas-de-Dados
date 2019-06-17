#include <stdio.h>

typedef struct tree tree;
typedef struct node node;

struct node 
{
    node *left;
    node *right;
    node *parent;
    int key;
    int color; //Red = 1, Black = 0
};


struct tree
{
    node *root;
    node *nil;
    int height;
};

int main()
{
    /*
    
        TEST CODE  

     */
}

//Method to rotate LEFT a binary search tree
void rotateLeft(tree *T, node *x)
{
    y = x -> right;
    x -> right = y -> left;
    if y -> left != NULL {(y -> left) -> parent = x;}

    y -> parent = x -> parent;
    if(x -> parent == NULL) {T -> root = y;}
    else if((x -> parent) -> left == x) {(x -> parent) -> left = y;}
    else {(x -> parent) -> right = y;}
    
    x -> parent = y;
    y -> left = x;
}

//Method to rotate RIGHT a binary search tree
void rotateRight(tree *T, node *y)
{
    x = y -> left;
    y -> left = x -> right;
    if(x -> right != NULL) {(x -> right) -> parent = y;}

    x -> parent = y -> parent;
    if(y -> parent == NULL) {T -> root = x;}
    else if((y -> parent) -> left == y) {(y -> parent) -> left = x;}
    else {(y -> parent) -> right = x;}

    y -> parent = x;
    x -> right = y;
}

//Method to insert node in a Red-Black tree
void rbInsert(tree *T, node *z)
{
    node *y = T -> nil;
    node *x = T -> root;

    while(x != T -> nil)
    {
        y = x;
        if(z -> key < x -> key) {x = x -> left;}
        else x = x -> right;
    }

    z -> parent = y;
    if(y == T -> nil) {T -> raiz = z;}

    else if(z -> key < y -> key) {y -> left = z;}

    else {y -> right = z;}

    z -> right = T -> nil;
    z -> left = T -> nil;
    z -> color = 1;

    rbInsertFixUp(T, z);
}

//Method to rebalance the tree after inserting an element
void rbInsertFixUp(tree *T, node *z)
{
    while((z -> parent) -> color == 1)
    {
        if(z -> parent == ((z -> parent) -> parent) -> left)
        {
            node *y = ((z -> parent) -> parent) -> right;
            if(y -> color == 1) // z uncle has color red
            {
                (z -> parent) -> color = 0;
                ((z -> parent) -> parent) -> color = 1;
                y -> color = 0;
                z = (z -> parent) -> parent;
            }

            else //z uncle has color black
            {
                if(z == (z -> parent) -> right) //z is right child
                {
                    z = z -> parent;
                    rotateLeft(T, z);
                }

                (z -> parent) -> color = 0;
                ((z -> parent) -> parent) -> color = 1;
                rotateRight(T, (z -> parent) -> parent);
            }
        }

        else
        {
            node *y = ((z -> parent) -> parent) -> left;
            if(y -> color == 1) //z uncle has color red
            {
                (z -> parent) -> color = 0;
                y -> color = 0;
                ((z -> parent) -> parent) -> color = 1;
                z = (z -> parent) -> parent;
            }

            else //z uncle has color black
            {
                if(z == (z -> parent) -> left)
                {
                    z = z -> parent;
                    rotateRight(T, z);
                }

                (z -> parent) -> color = 0;
                ((z -> parent) -> parent) -> color = 1;
                rotateLeft(T, (z -> parent) -> parent);
            }
        }
    }

    (T -> root) -> color = 0;
}

void rbTransplant(tree *T, node *u, node *v)
{
    if(u -> parent == T -> nil) {T -> root = v;}

    else if(u == (u -> parent) -> left) {(u -> parent) -> left = v;}

    else {(u -> parent) -> right = v;}

    v -> parent = u -> parent; 
}

//Iterative method to find the minimum value in a tree
node *treeMinimum(node *x)
{
    while(x -> left != NULL) {x = x -> left;}

    return x;
}


void rbDelete(tree *T, node *z)
{
    node *y = z;
    int yCorOriginal = y -> color;
    
    if(z -> left == T -> nil)
    {
        node *x = z -> right;
        rbTransplant(T, z, z -> right);
    }

    else if(z -> right = T -> nil)
    {
        node *x = z -> left;
        rbTransplant(T, z, z -> left);
    }

    else
    {
        y = treeMinimum(z -> right);
        yCorOriginal = y -> color;
        node *x = y -> right;
        if(y -> parent == z)
        {
            x -> parent = y;
        }

        else
        {
            rbTransplant(T, y, y -> right);
            y -> right = z -> right;
            (y -> right) -> parent = y;
        }
        
        rbTransplant(T, z, y);
        y -> left = z -> left;
        (y -> left) -> parent = y;
        y -> color = z -> color;
    }

    if(yCorOriginal == 0)
    {
        rbDeleteFixup(T, x);
    }
}


void rbDeleteFixup(tree *T, node *x)
{
    while(x != T -> root && x -> color == 0)
    {
        if(x == (x -> parent) -> left)
        {
            node *w = (x -> parent) -> right;
            if(w -> color == 1)
            {
                w -> color = 0;
                (x -> parent) -> color = 1;

                rotateLeft(T, x -> parent);

                w = (x -> parent) -> right;
            }

            if((w -> left) -> color == 0 && (w -> right) -> color == 0)
            {
                w -> color = 1;
                x = x -> parent;
            }

            else if((w -> right) -> color == 0)
            {
                (w -> left) -> color = 0
                w -> color = 1;
                rotateRight(T, w);
                w = (x -> parent) -> right;
            }

            w -> color = (x -> parent) -> color;
            (x -> parent) -> color = 0;
            (w -> right) -> color = 0;
            rotateLeft(T, x -> parent);
            x = T -> root;
        }

        else
        {
            //Sames as if with "Right" and "left" exchanged
        }
        
    }

    x -> color = 0;
}