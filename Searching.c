#include<stdio.h>

int  linearSearch(int *array , int size , int element){
    for(int i = 0 ; i<size ; i++)
    {
        if( array[i] == element)
        {
            return i;
        }
    }
    return -1;

}

int binarySearch(int *array , int size , int element){
int low = 0 ;
int high = size-1 ;
while(low<=high)
{
    int mid = (low + high)/2;
    printf("The mid value %d \n" , mid);
    if(array[mid] == element)
    {
        return mid;
    }
    if(array[mid]>element)
    {
        high = mid-1;
    printf("The high value %d \n" , high);

    }
    else{
        low = mid+1;
    printf("The low value %d \n" , low);

    }
}
return -1;
}


int main(){ 
    //Unsorted Array
    // int array[]= {3,4,5,2,78,98,23,45};
    // int size = sizeof(array)/sizeof(int);
    // int element ;
    // printf("Enter the searching element : ");
    // scanf("%d" , &element);
    // int a =  linearSearch(array , size , element) ; 
    
    //    printf("Searching is successfull !\n");
    //     printf("The index is  : %d " , a);
    
    //Binary Search => Always work on sorted arrays
    
    int array[10];
    for(int i = 0 ; i<10 ; i++)
    {
        array[i] = i;
    // printf("%d " , array[i]);
    }
    
    int size = sizeof(array)/sizeof(int);
     int element;
     printf("Enter the element of array to search : ");
     scanf("%d" , &element);
     int searchingIndex = binarySearch(array , size , element);
     printf("The element %d is at index %d" , element , searchingIndex );


     return 0;
}