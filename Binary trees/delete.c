#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *construct(struct node *n, int data)
{
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// InOrder Traversal
void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

struct node* inOrderPredecessor(struct node *root)
{
    root = root->left;
    while(root->right !=NULL)
    {
        root = root->right;
    }
    return root;

}

struct node *deleteNode(struct node *root, int value)
{
        struct node *iPre;

if(root == NULL){
    return NULL;
}
if(root->left ==NULL && root->right == NULL )
{
    free(root);
    return NULL;
}

    //Search for the node to be deleted
    if (value < root->data)
    {
       root->left =  deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
       root->right =  deleteNode(root->right, value);
    }
    else
    {
        //Deletion Strategy when the node is found
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left , iPre->data);
    }
    return root;
}

int main()
{
    // Constructing root node
    struct node *p = construct(p, 5);
    struct node *p1 = construct(p1, 3);
    struct node *p2 = construct(p2, 1);
    struct node *p3 = construct(p3, 4);
    struct node *p4 = construct(p4, 6);

    p->left = p1;
    p->right = p4;

    p1->left = p2;
    p1->right = p3;

    inOrder(p);
    printf("\n ");
    deleteNode(p , 1);
    inOrder(p);



    return 0;
}