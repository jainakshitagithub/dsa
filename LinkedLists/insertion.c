#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void linkedListsTraversal(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct node * insertAtStart(struct node *head , int data){
   struct node *p;
   p = (struct node *)malloc(sizeof(struct node));
   p->data = data;
   p->next = head;
   return p;
}

struct node * insertAtIndex(struct node *head , int data , int index)
{
    struct node *ptr;
    struct node *p = head;
    ptr = (struct node *)malloc(sizeof(struct node));
    int i=0;
    while(i<index){
     p = p->next; 
     i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    ptr->data = data;
    return head;
}

struct node * insertAtEnd(struct node *head , int data){
   struct node *p;
   struct node *ptr = head;
   p = (struct node *)malloc(sizeof(struct node));

   while(ptr->next!=NULL){
   ptr = ptr->next;
   }
   ptr->next = p;
   p->next = NULL;
   p->data = data;
   return head;
}

void insertAfterNode(struct node *head ,struct node *node,  int data)
{
    struct node *p = (struct node*)malloc(sizeof(struct node));
    p->next = node->next;
    node->next = p;
    p->data = data;

}

int main()
{
    struct node *head, *first, *second, *third;

    head = (struct node *)malloc(sizeof(struct node));
    first = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    head->data = 12;
    head->next = first;

    first->data = 21;
    first->next = second;

    second->data = 56;
    second->next = third;

    third->data = 34;
    third->next = NULL;


//Before Insertion
printf("Before Insertion\n");
    linkedListsTraversal(head);

//After Insertion
    //Insertion at the beginnning
    // head = insertAtStart(head , 77);
    // head = insertAtIndex(head , 77 , 1);
    // head = insertAtEnd(head , 100);
     insertAfterNode(head , second , 766);




printf("After Insertion\n");
    
    linkedListsTraversal(head);
  

    return 0;
}