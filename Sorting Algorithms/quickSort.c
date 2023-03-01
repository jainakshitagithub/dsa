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

int partition(int *A , int low , int high){
    int pivot = A[low];
    int i = low+1;
    int j = high;
  do{
      while(A[i]<=pivot)
    {
        i++;
    }
    while(A[j]>pivot){
        j--;
    }
    if(i<j){
        swap(&A[i] , &A[j]);
    }
  }while(i<j);
  swap(&A[low] , &A[j] );
  return j;
}

void quickSort(int *A , int low, int high){
if(low<high){
    int partitionIndex = partition(A,low , high);
    quickSort(A , partitionIndex+1 , high);//Recursive Call
    quickSort(A , low ,partitionIndex-1);

}
}


int main(){ 
    int A[]= {1,2,9,4,5,6,7};
    int n = 7;
    display(A , n);//displays before selection Sort 
    quickSort(A , 0 , n-1);
    printf("\n");
   display(A , n);//displays after selection Sort 
     return 0;
}