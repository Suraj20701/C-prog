#include<stdio.h>

void Merge(int a[], int low, int mid, int high){
    int i, j, k, b[20];
    i = low;
    j = mid + 1;
    k = 0;

    while (i<=mid && j <= high)
    {
        if(a[i]<=a[j])
          b[k++] = a[i++];
        else
          b[k++] = a[j++];
    }
    
    while(i<=mid) b[k++] = a[i++];
    while(j<=high) b[k++] = a[j++];

    for (k = 0;k<=high;k++)
    {
        a[k] = b[k];
    }
}

void merge_sort(int a[], int low, int high){
    int mid;
    if (low<high)
    {
        mid = (low+high)/2;



        
        merge_sort(a, low, mid);
        merge_sort(a, mid+1, high);
        Merge(a, low, mid, high);
    }
}

int main()
{
    int a[5] = {1,2,3,4,5};
    merge_sort(a,0,4);
    for (int i = 0; i < 5; i++)
    {
        printf("%d\t", a[i]);
    }
    
    
    return 0;
}
