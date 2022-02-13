// C program to find the smallest element in an array of 10 elements using pointers.

#include<stdio.h>

int main(){
    int *p,a[10],i,n,min;
    printf("Enter the size of an array\n");
    scanf("%d",&n);
    
    p=a;
    printf("Enter the array elements\n");
    for(i=0;i<n;i++){
        scanf("%d",p+i);
    }

    min = *p;
    for(i=0;i<n;i++){
              if(*(p+i)<min){                  
                 min = *(p+i);
              }
    }

    printf("The smallest element in the array is %d\n",min);

    return 0;

}