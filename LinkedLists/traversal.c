#include <stdio.h>
#include <stdlib.h>

// Self refrencing structure
struct node
{
    int data;
    struct node *next;
};

void linkedListsTravesal(struct node *head){

struct node *ptr = head;

while(ptr!=NULL){
     printf("The element : %d\n" , ptr->data);
    ptr = ptr->next;
}
}


int main()
{

//Creation of Linked lists
    struct node *head;
    struct node *first;
    struct node *second;
    struct node *third;

//Requesting dynamic memory in heap of struct datatype pointer
    head = (struct node *)malloc(sizeof(struct node));
    first = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

//head node that point to next
    head->data = 12;
    head->next = first;

    first->data = 34;
    first->next = second;

    second->data = 12;
    second->next = third;

//last node of the linked lists that points to null
    third->data = 56;
    third->next = NULL;

//Function of traversal
linkedListsTravesal(head);


    return 0;
}