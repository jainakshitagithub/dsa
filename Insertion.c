#include <stdio.h>

void display(int *arr, int n)
{
    // Traversal code
    for (int i = 0; i < n; i++)
    {
        printf("The Array element %d : %d\n", i, arr[i]);
    }
}

int indInsertion(int *array, int size, int capacity, int element, int index)
{
    //Insetion basic code
    if (size >= capacity)
    {
        return -1;
    }
    else
    {

        for (int i = size - 1; i >= index; i--)
        {
            array[i + 1] = array[i];
        }
        array[index] = element;
        return 1;
    }
}

int main()
{
    int array[100] = {7, 8, 12, 48, 34};
    int size = 5, capacity = 100, element, index,a;
    printf("Enter the element to insert : ");
    scanf("%d", &element);

    printf("Enter the index : ");
    scanf("%d", &index);

  a =  indInsertion(array, size, capacity, element, index);
 if(a == 1)
 {
    printf("Insertion is successfull !\n");
      size++;
    display(array, size);
 }
 else{
    printf("Insertion failure !\n");
 }

    
        return 0;
}