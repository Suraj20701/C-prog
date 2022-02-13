#include<stdio.h>
int main(){
int a[10],i,j,n,temp, min;

printf("Enter the size of array\n");
scanf("%d",&n);

printf("Enter the array elememts\n");
for(i=0;i<n;i++)
    scanf("%d",&a[i]);

printf("Array before sorting : ");
for(i=0;i<n;i++)
    printf("%d\t",a[i]);

// bubbleSort
for(j=1;j<=n-1;j++)
    for(i=0;i<=n-j-1;i++)
        if(a[i]>=a[i+1]){
            temp=a[i];
            a[i]=a[i+1];
            a[i+1]=temp;
            }


Selection sorting
for(i=0;i<n-1;i++){
      min=i;
      for(j=i+1;j<n;j++){
	          if(a[j]<a[min])
	          min=j;
             }
     temp=a[i];
     a[i]=a[min];
     a[min]=temp;
  }

printf("\nAfter sorting : ");
for(i=0;i<n;i++)
    printf("%d\t",a[i]);
return 0;
}

