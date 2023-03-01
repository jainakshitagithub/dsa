#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node * construct(struct node *n , int data){
    n  = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void inOrder(struct node *root){
if(root!=NULL){
    inOrder(root->left);
    printf("%d " , root->data);
    inOrder(root->right);
}
}

int isBST(struct node *root){
    static struct node * prev = NULL;
    if(root!=NULL)
    {
        if(!isBST(root->left))
        {
            return 0;
        }
        if(prev!=NULL && prev->data>=root->data)
        {
            return 0;
        }
        prev = root;
       return isBST(root->right);

    }
    else{
        return 1;
    }
}

int main(){ 
    struct node *p = construct(p , 5);
    struct node *p1  = construct(p1 , 3);
    struct node *p2  = construct(p2 , 1);
    struct node *p3  = construct(p3 , 4);
    struct node *p4  = construct(p4 , 6);

    p->left = p1;
    p->right = p4;

    p1->left = p2;
    p1->right = p3;

 inOrder(p);
printf("\n");
printf("%d " , isBST(p));
    

    
     return 0;
}