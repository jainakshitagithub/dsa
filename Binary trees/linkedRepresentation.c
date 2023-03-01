#include<stdio.h>
#include<stdlib.h>

struct node{
     int data;
     struct node *left;
     struct node *right;
};

struct node * construct(struct node *n , int data){
 n = (struct node *)malloc(sizeof(struct node));
 n->data = data;
 n->left = NULL;
 n->right = NULL;
return n;
}
//PreOrder Traversal
void preOrder(struct node*root){
    if(root!=NULL){
        printf("%d " , root->data);
        preOrder(root->left);
        preOrder(root->right);

    }
}

//PostOrder Traversal
void postOrder(struct node *root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d " , root->data);

    }
}

//InOrder Traversal
void inOrder(struct node *root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d " , root->data);
        inOrder(root->right);

    }
}

int main(){ 
    //Constructing root node
    struct node *p = construct(p , 4);
    struct node *p1 = construct(p1 , 1);
    struct node *p2 = construct(p2 , 5);
    struct node *p3 = construct (p3 , 2);
    struct node *p4 = construct (p4 , 6);

    p->left = p1;
    p->right = p4;

    p1->left = p2;
    p1->right = p3;

printf("PreOrder Traversal : ");
preOrder(p);
printf("\nInOrder Traversal : ");
inOrder(p);
printf("\nPostOrder Traversal : ");
postOrder(p);

     
     return 0;
}