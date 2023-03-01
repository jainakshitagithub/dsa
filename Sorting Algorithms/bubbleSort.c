#include<stdio.h>

void display(int *A,int n){
 for(int i = 0 ; i<n ; i++){
    printf("%d " , A[i]);
 }
}

void swap(int *a , int *b)
{
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSortAdaptive(int *A , int n){
    int sorted = 0;
for(int i =0 ; i <n-1 ; i++){
    printf("Working of the pass number :  %d\n" , i+1);
    sorted = 1;
    for(int j =0 ;j<n-1-i ; j++)
    {
        if(A[j]>A[j+1])
        {
           sorted = 0;
           swap(&A[j] , &A[j+1]);
        }
    }
    if(sorted){
        return ;
    }
}
}

void bubbleSort(int *A , int n){
for(int i =0 ; i <n-1 ; i++){
    printf("Working of the pass number :  %d\n" , i+1);
    for(int j =0 ;j<n-1-i ; j++)
    {
        if(A[j]>A[j+1])
        {
           swap(&A[j] , &A[j+1]);
        }
    }
}
}

int main(){ 
    int A[]= {1,2,9,4,5,6,7};
    int n = 7;
    display(A , n);//displays before bubble Sort
    // bubbleSort(A , n);
    bubbleSortAdaptive(A , n);
   display(A , n);//displays after bubble Sort
     return 0;
}