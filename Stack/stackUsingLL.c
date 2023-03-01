#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

void linkedListTraversal(struct node *top)
{
    struct node *ptr = top;
   while(ptr!=NULL)
   {
    printf("The element : %d \n" , ptr->data);
    ptr = ptr->next;
   }
}

int isEmpty(struct node *top)
{
    if(top==NULL)
    {
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct node *ptr)
{
    ptr = (struct node *)malloc(sizeof(struct node));
    if(ptr==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
struct node * push(struct node *top , int data)
{
    if(isFull(top))
    {
        printf("Stack overflow\n");
        return top;
    }
    else{
      struct node *ptr = (struct node*)malloc(sizeof(struct node));
      ptr->data = data;
      ptr->next = top;
      top = ptr;
      return top;
    }
}

int pop(struct node **top){
    if(isEmpty(*top))
    {
        printf("Stack underflow\n");
        return -1;
    }
    else{
        struct node *n = *top;
        *top = (*top)->next;
        int x = n->data;
        free(n);
        return x;
    }
}

int stackTop(struct node *top){
    return top->data;
}
int stackBottom(struct node *top){
    struct node *ptr = top;
    while(ptr->next !=NULL)
    {
        ptr = ptr->next;
    }
    return ptr->data;
}

int peek(struct node *top , int pos){

struct node *ptr = top;
  for(int i= 0 ;(i<pos-1 && ptr!=NULL) ; i++)
  {
    ptr = ptr->next;
  }
  if(ptr!=NULL)
  {
    return ptr->data;
  }
  else{
    return -1;
  }
}

int main(){ 
    struct node *top = NULL;
    printf("The full : %d\n" , isFull(top));
    printf("The Empty : %d\n" , isEmpty(top));

top = push(top , 28);
top = push(top , 18);
top = push(top , 15);
top = push(top , 7);

// linkedListTraversal(top);
int a = pop(&top);
// linkedListTraversal(top);
for(int i  = 1 ; i<5 ; i++)
{
    printf("%d " , peek(top , i));
}

printf("Stack top %d\n",stackTop(top));
printf("Stack bottom %d\n",stackBottom(top));





    printf("The full : %d\n" , isFull(top));
    printf("The Empty : %d\n" , isEmpty(top));

     return 0;
}