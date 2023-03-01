#include<stdio.h>

void display(int *A,int n){
 for(int i = 0 ; i<n ; i++){
    printf("%d " , A[i]);
 }
}

void insertionSort(int *A , int n){
    for(int i =1 ; i < n ; i++){
        int key = A[i];
        int j = i-1;
        while(j>=0 && A[j]>key){
            A[j+1]  = A[j];
            j--;
        }
        A[j+1] = key;
    }
}


int main(){ 
    int A[]= {1,2,9,4,5,6,7};
    int n = 7;
    display(A , n);//displays before insertion Sort 
    insertionSort(A , n);
    printf("\n");
   display(A , n);//displays after insertion Sort 
     return 0;
}