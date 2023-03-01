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

struct node *deleteFirstNode(struct node *head)
{
    struct node *ptr = head;
    head = ptr->next;
    free(ptr);
    return head;
}

struct node *deleteAtIndex(struct node *head, int index)
{
    struct node *q;
    struct node *ptr = head;
    int i = 0;
    while (i != index - 1)
    {
        ptr = ptr->next;

        i++;
    }
    q = ptr->next;
    ptr->next = q->next;
    free(q);
    return head;
}

struct node *deleteAtEnd(struct node *head)
{
    struct node *ptr = head;
    struct node *q = head->next;
    while (q->next != NULL)
    {
        ptr = ptr->next;
        q = q->next;
    }
ptr->next = NULL;
 free(q);
    return head;
}

void deleteAfterNode(struct node *head , struct node *node)
{
    struct node *q = node->next;
    node->next = q->next;;
    free(q);
}


struct node * deleteAtGivenValue(struct node *head , int value)
{
  struct node *ptr = head;
  struct node *q = head->next;
  while(q->data != value && q->next != NULL){
  q = q->next;
  ptr = ptr->next;
  }
  if(q->data == value)
  {
    ptr->next = q->next;
    free(q);
  }
    return head;
}

int main()
{
    struct node *head, *first, *second, *third, *fourth;

    head = (struct node *)malloc(sizeof(struct node));
    first = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    head->data = 12;
    head->next = first;

    first->data = 21;
    first->next = second;

    second->data = 56;
    second->next = third;

    third->data = 34;
    third->next = fourth;

    fourth->data = 234;
    fourth->next = NULL;

    printf("Before Deletion\n");
    linkedListsTraversal(head);
    // Deletion at first
    //  head = deleteFirstNode(head);
    // Deletion at index
    // head = deleteAtIndex(head, 2);
    //Deletion at End
    //   head = deleteAtEnd(head);
    //Deletion After node
    // deleteAfterNode(head, first);
    //Deletion At given Value
//    head =  deleteAtGivenValue(head , 234);


    printf("After Deletion\n");
    linkedListsTraversal(head);

    return 0;
}