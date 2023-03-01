#include<stdio.h>

void display(int *A,int n){
 for(int i = 0 ; i<n ; i++){
    printf("%d " , A[i]);
 }
}

void swap(int *a , int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int *A , int n){
    printf("\nRunning Selection Sort Algorithm...\n");
   for(int i = 0 ; i<n ; i++){
    int indexOfMin = i;

    for(int j = i+1 ; j<n ; j++)
    {
            if(A[j]<A[indexOfMin])
            {
                indexOfMin = A[j];
            }
    }
   swap(&A[indexOfMin] , &A[i]);
   }
}


int main(){ 
    int A[]= {1,2,9,4,5,6,7};
    int n = 7;
    display(A , n);//displays before selection Sort 
    selectionSort(A , n);
   display(A , n);//displays after selection Sort 
     return 0;
}