#include<stdio.h>
#include<stdlib.h>


//Abstract Data Types are the custom Data Types 

struct myArray{
 int total_size;
 int used_size;
 int *ptr;
};

void createArray( struct myArray *a , int tsize , int usize){
    a->total_size = tsize;
    a->used_size = usize;
    a->ptr = (int *)malloc(tsize*sizeof(int));
}

void setArray(struct myArray *a)
{
    int n;
    for(int i =0 ; i<a->used_size ; i++)
    {
        printf("Enter the element %d : " , i+1);
        scanf("%d" , &n );
        a->ptr[i] = n;
    }
}

void showArray(struct myArray *a)
{
    int n;
    for(int i =0 ; i<a->used_size ; i++)
    {
        printf("The %d element of array is %d\n" ,i+1, a->ptr[i]);
    }
}

int main(){ 
    struct myArray marks;
    createArray(&marks , 10 , 2);
    setArray(&marks);
    showArray(&marks);
     return 0;
}