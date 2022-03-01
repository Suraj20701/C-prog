#include <stdio.h>

void binary_search_assn(int a[], int key, int min, int max)
{
    int mid;
    if (min > max)
        printf("Key not found");
    mid = (min + max) / 2;

    if (key == a[mid])
        printf("Key found at %d index\n",mid);
    else if (key < a[mid])
        binary_search_assn(a, key, min, mid - 1);
    else
        binary_search_assn(a, key, mid + 1, max);
}

void binary_search_desn(int a[], int key, int min, int max)
{
    int mid;
    if (min > max)
        printf("Key not found\n");
    mid = (min + max) / 2;

    if (key == a[mid])
        printf("Key found at %d index\n",mid);
    else if (key > a[mid])
        binary_search_desn(a, key, min, mid - 1);
    else
        binary_search_desn(a, key, mid + 1, max);
}


void take_input(int a[], int n)
{
    int num;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    
}

void main()
{
    int a[10], size, key, choice, continue_search;

    while (1)
    {
        printf("\n\nChoose a option :\n 1.Enter array in asending order\n 2.Enter array in desending order\n 3.Change Key \n 4.Exit \n Choose option >> ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the size of an array : ");
            scanf("%d",&size);
            printf("Enter array in asending order : ");
            take_input(a,size);
            while (1)
            {
            printf("Enter the key to be searched : ");
            scanf("%d",&key);
            binary_search_assn(a,key,0,size-1);
            printf("Enter 1 to search another key 0 to change array : ");
            scanf("%d",&continue_search);
            if (!continue_search)
                break;
            }
            break;

        case 2:
            printf("Enter the size of an array : ");
            scanf("%d",&size);
            printf("Enter array in desending order : ");
            take_input(a,size);
            while (1)
            {
            printf("Enter the key to be searched : ");
            scanf("%d",&key);
            binary_search_desn(a,key,0,size-1);
            printf("Enter 1 to search another key 0 to change array : ");
            scanf("%d",&continue_search);
            if (!continue_search)
                break;
            }
            break;
        
        default:
            printf("Please enter the valid option....");
            break;
        }
    }
    
}