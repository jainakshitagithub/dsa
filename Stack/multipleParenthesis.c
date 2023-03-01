#include <stdio.h>
#include <stdlib.h>

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

int isMatch(char a , char b)
{
    if(a=='(' && b==')')
    {
        return 1;
    }
    if(a=='{' && b=='}')
    {
        return 1;
    }
    if(a=='[' && b==']')
    {
        return 1;
    }
    return 0;
}

int multipleParenthesis(const char *exp){
struct stack *sp;
sp->size = 100;
sp->top = -1;
sp->arr = (char *)malloc(sp->size * sizeof(char));

for(int i =0 ; exp[i]!='\0' ; i++){
    if(exp[i]== '(' || exp[i]=='{' || exp[i]=='[')
    {
        push(sp,exp[i]);
    }
    else if(exp[i]== ')' || exp[i]=='}' || exp[i]==']')
    {
        if(isEmpty(sp))
        {
            return 0;
        }
        if(!isMatch( pop(sp) , exp[i] ))
        {
            return 0;
        }

    }
}
if(isEmpty(sp)){
    return 1;
}
else{
    return 0;
}
}

int main()
{

    const char *exp = "[4-6((]8){(9-8)})";

    if (multipleParenthesis(exp))
    {
        printf("Balanced Expression");
    }
    else
    {
        printf("Unbalanced Expression");
    }

    return 0;
}