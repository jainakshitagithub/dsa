#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void display(int *A,int n){
 for(int i = 0 ; i<n ; i++){
    printf("%d " , A[i]);
 }
}

int maximun(int A[] , int n){
  int max = INT_MIN;
  for(int i = 0 ; i<n ; i++){
    if(max<A[i])
    {
        max = A[i];
    }
  }
  return max;
}

void countSort(int A[] , int n){
 int i , j;
  //Find maximun in the  array
  int max = maximun(A , n);

  //Create a count Array uptil the maximum
  int *count = (int *)malloc((max+1) * sizeof(int));

  //intialize them with 0
  for( i = 0 ; i<max+1 ; i++){
    count[i] = 0;
  }

  //intialize the count by given Array
  for( i =0 ; i<n ; i++)
  {
    count[A[i]] = count[A[i]]+1; 
  }


 i =0; //count Array
 j = 0;//given Array
  while(i<=max)
  {
    if(count[i]>0)
    {
        A[j] = i;
        count[i] = count[i]-1;
        j++;
    }
    else{
        i++;
    }
  }

}

int main(){ 
        int A[]= {1,2,9,4,5,6,7};
    int n = 7;
    display(A , n);
    printf("\n");
    countSort(A , n);
   display(A , n);
     return 0;
     return 0;
}




