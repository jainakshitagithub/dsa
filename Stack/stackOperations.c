#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int full(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int empty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, int value)
{
    if (full(ptr))
    {
        printf("Stack overflow , the %d value cannot push into the stack\n", value);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

int pop(struct stack *ptr)
{
    if (empty(ptr))
    {
        printf("Stack underflow , the element cannot be popped now\n");
        return -1;
    }
    else
    {
        int value = ptr->top;
        //    ptr->arr[ptr->top--];
        ptr->top--;

        return value;
    }
}

int peek(struct stack *ptr, int i)
{
    int arrInd = ptr->arr[ptr->top - i + 1];
    printf("The indices value %d\n", ptr->top - i + 1);
    if (arrInd < 0)
    {
        printf("Invalid expression %d\n", i);
        return -1;
    }
    else
    {
        return arrInd;
    }
}

int stackTop(struct stack *ptr){
    return ptr->arr[ptr->top];
}

int stackBottom(struct stack *ptr){
    return ptr->arr[0];
}

int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 3;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    // pushing the value->cannot be pushed once stack is full

    push(s, 455);
    push(s, 234);
    push(s, 221);
    // pop(s);
    // pop(s);
    // pop(s);
    printf("Full : %d\n", full(s));
    printf("Empty : %d\n", empty(s));

    for (int i = 1; i <= s->size; i++)
    {
        printf("The value of %d position is %d\n", i, peek(s, i));
    }
  
  printf("The Topmost element of the stack is %d\n" , stackTop(s));
  printf("The Bottommost element of the stack is %d\n" , stackBottom(s));

    return 0;
}