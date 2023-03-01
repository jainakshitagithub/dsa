#include<stdio.h>

int indDeletion(int *array , int size , int index ){
for(int i = index ; i<size-1 ; i++)
{
    array[i] = array[i+1];
}
    return 1;
}

void display(int *array , int size)
{
 for(int i = 0 ;i<size ; i++)
 {
    printf("%d " , array[i]);
 }
}

int main(){ 
    int array[] = {7,8,12,34,56};
    int index;
    int size = sizeof(array)/sizeof(int);
    printf("Size of Array is %d\n" , size);
    printf("Enter the index for deletion : ");
    scanf("%d" , &index);
    int a = indDeletion(array , size , index );
    if(a == 1)
    {
printf("Deletion is successfull !\n");
    size--;
    display(array , size);

    }
     return 0;
}