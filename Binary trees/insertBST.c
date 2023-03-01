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

void insertBST(struct node *root , int key){
    struct node *prev = NULL;
    while(root!=NULL){
        prev = root;
        if(root->data == key)
        {
            printf("Cannot insert %d already in BST" , key);
            return;
        }
        else if(root->data>key){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    struct node * ptr = construct(ptr , key);
    if(key<prev->data)
    {
        root->left = ptr;
    }
    else{
        root->right = ptr;
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

    insertBST(p , 0);

     return 0;
}