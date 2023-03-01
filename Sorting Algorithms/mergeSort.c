#include <stdio.h>
void display(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
}

void merge(int A[], int low, int mid, int high)
{
    printf("Running merge function  ....low %d ,mid %d ,high %d\n" , low ,mid, high);
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }

    while (i <= mid)
    {
        B[k] = A[i];
        i++;
        k++;
    }

    while (j <= high)
    {
        B[k] = A[j];
        j++;
        k++;
    }
    for(int i = low ; i<=high ; i++)
    {
        A[i] = B[i];
    }
}

void mergeSort(int A[] , int low , int high){
if(low<high){
    int mid = (low+high)/2;
    printf("1 low %d ,mid %d ,high %d \n" , low ,mid, high);
    mergeSort(A, low , mid);

    printf("2  low %d ,mid %d ,high %d \n" , low ,mid, high);
    mergeSort(A , mid+1 , high);

    merge(A, low , mid , high);
}
}


int main()
{
    int A[] = {1, 2, 9, 4, 5, 6, 7};
    int n = 7;
    display(A, n); // displays before merge Sort
   printf("\n");
   mergeSort(A , 0 , 6);
    display(A, n); // displays after merge Sort
    return 0;
}