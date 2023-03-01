#include <stdio.h>
#include <stdlib.h>

struct node *f = NULL;
struct node *r = NULL;

struct node
{
    int data;
    struct node *next;
};

void linkedListsTravesal(struct node *ptr){

printf("Printing elements of this linked list\n");
while(ptr!=NULL){
     printf("The element : %d\n" , ptr->data);
    ptr = ptr->next;
}
}

isFull(struct node *n)
{
    if (n == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

isEmpty(struct node *f)
{
    if (f == NULL)
    {
        return 1;
    }
    return 0;
}

void enqueue(int val)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (isFull(n))
    {
        printf("No element to enqueue\n");
    }
    else
    {
        n->next = NULL;
        n->data = val;
        if (isEmpty(f))
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}

int dequeue()
{
    int a = -1;
    if (isEmpty(f))
    {
        printf("No element to dequeue\n");
        return a;
    }
    else
    {
        struct node *ptr;
        ptr = f;
        f = f->next;
        a = ptr->data;
        free(ptr);
        return a;
    }
}

int main()
{
    struct node *f = NULL;
    struct node *r = NULL;
    enqueue(6);
    enqueue(1);
    enqueue(8);
    linkedListsTravesal(f);

    printf("Dequeuing element : %d\n", dequeue());

    linkedListsTravesal(f);

    return 0;
}