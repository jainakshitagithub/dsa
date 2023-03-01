#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct stack
{
    int size;
    int top;
    char *arr;
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

int isEmpty(struct stack *ptr)
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

void push(struct stack *ptr, char value)
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

char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack underflow , the element cannot be popped now\n");
        return -1;
    }
    else
    {
        char value = ptr->top;
        //    ptr->arr[ptr->top--];
        ptr->top--;

        return value;
    }
}

char stackTop(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}

int isOperator(char ch){
    if((ch == '+')||(ch == '-')||(ch == '*')||(ch == '/'))
    {
        return 1;
    }
    return 0;
}

int precedence(char ch)
{
    if(ch=='*' || ch=='/'){
        return 3;
    }
    else if(ch=='+' || ch== '-')
    {
        return 2;
    }
    else {
        return 0;
    }
}
char * infixToPostfix(const char *infix){
    struct stack *sp = (struct stack*)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char *postfix = (char *)malloc((strlen(infix)+1) * sizeof(char));

    char i ;//For infix
    char j ;//For Postfix

    while(infix[i] != '\0')
    {
        if(!isOperator(infix[i])){
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else if(precedence(infix[i])>precedence(stackTop(sp)))
        {
            push(sp,  infix[i]);
            i++;
        }
        else{
           postfix[j]= pop(sp);
           j++;
        }
    }
    if(!isEmpty(sp)){
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';

    return postfix;

}

int main()
{
//Program not returning any result,,don't know why
  const char *infix = "a-b";
   printf("Postfix Exp : %s" , infixToPostfix(infix) );


    return 0;
}