
/*
Binary Search is a searching algorithm used in a sorted array by repeatedly dividing the search interval in half. 
The idea of binary search is to use the array that  is sorted and reduce the time complexity to O(Log n). 



*/ 
#include <stdio.h>
int a[10], size, key;

void binary_iteration()
{
    int min = 0, max = size - 1;
    while (min <= max)
    {
        int mid = (min + max) / 2;
        if (a[mid] == key)
        {
            printf("\nKey element found at %d index", mid);
            return;
        }

        else if (key < a[mid])
            max = mid - 1;

        else
            min = mid + 1;
    }
    printf("\nKey element not found");
}

void binary_recursive(int min, int max)
{
    if (min > max)
    {
        printf("\nKey element not found");
        return;
    }

    int mid = (min + max) / 2;

    if (a[mid] == key)
    {
        printf("\nKey element found at %d index", mid);
        return;
    }

    else if (key < a[mid])
        binary_recursive(min, mid - 1);

    else
        binary_recursive(mid + 1, max);
}

int main(int argc, char const *argv[])
{
    printf("Enter the size of an array : ");
    scanf("%d", &size);

    printf("Enter the array elements : ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter the key element : ");
    scanf("%d", &key);

    binary_iteration();
    binary_recursive(0, size - 1);

    return 0;
}
