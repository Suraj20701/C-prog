//  C program to create a dynamic array of integers using pointers.

#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,i,*p;
    printf("Enter the number of array elements\n");
    scanf("%d",&n);

    p = (int *) malloc(2*sizeof(int));
     if(p == 0){
         printf("Insufficient memory\n");
         exit(1);
     }

     printf("Enter the array elements\n");
     for(i=0;i<n;i++)
        scanf("%d",p+i);

    printf("The array elements are\n");
    for(i=0;i<n;i++){
        printf("%d\n",*(p+i));
    }

    free(p);
    
    return 0;
}