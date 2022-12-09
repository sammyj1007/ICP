#include <stdio.h>
#include<stdlib.h>

struct binarytreenode
{
    int data;
    struct binarytreenode *left;
    struct binarytreenode *right; // each node has two pointers
};

struct binarytreenode *insert(struct binarytreenode *root, int d) 
{
    struct binarytreenode *newnode;
    if(root == NULL) 
    {
        newnode = (struct binarytreenode *) malloc(sizeof(struct binarytreenode));
        newnode->data = d;
        newnode->left = NULL;
        newnode->right = NULL;
        return (newnode); // Create a new node ponly if you have reached the end of branch
    }
    else if(d <= root->data) 
    {
        root->left = insert(root->left, d); // keeps moving across the left branch
        return(root);   // if input data is lesser than or equal the value we have, we keep moving
    }
    else if(d > root->data) {
        root->right = insert(root->right, d); // keeps moving across the right branch
        return(root);    // if input data is greater than the value we have, we keep moving
    }
    else
    {
        return NULL; // just there to return all control paths
    }
}
void display(struct binarytreenode *root, int depth) {
    int i;
    if(root != NULL) 
    {
        display(root->right, depth+1);
        for(i = 0; i < depth; i++) printf("   ");// Spaces so that we can see the binary tree properly
        printf("%d\n", root->data);
        display(root->left, depth+1); // move it along the path
    }
}

int main()
{
    struct binarytreenode *root = NULL;
    root = insert(root, 15);
    root = insert(root, 7);
    root = insert(root, 23);
    root = insert(root, 30);
    root = insert(root, 18);
    root = insert(root, 43);
    root = insert(root, 42);
    root = insert(root, 1);
    root = insert(root, 93);
    root = insert(root, 2);
    root = insert(root, -33);
    root = insert(root, 4);
    root = insert(root, 23);
    display(root, 0);

    return 0;
}