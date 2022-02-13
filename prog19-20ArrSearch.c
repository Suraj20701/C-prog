#include<stdio.h>

int main(){
int a[10],n,key,low,high,i,flag,mid;

printf("Enter the size of array\n");
scanf("%d",&n);

printf("Enter the array elements\n");
    for(i=0;i<n;i++)
       scanf("%d",&a[i]);

printf("Enter the key element to be searched\n");
    scanf("%d",&key);
    
// Linear Search
for(i=0; i<n; i++){
    if(a[i] == n){
        flag = 1;
        break;
    }
}

// Binary Search
low=0;
high=n-1;
while(low<=high){
    mid=(low+high)/2;
    if(key==a[mid]){
        flag = 1;
        break;
      }
    else if(key<a[mid]){
      high=mid-1;
        }
    else
      low=mid+1;
  }

if(flag==1)
    printf("Search is successful key element found\n");
else
    printf("Search is unsuccessful key element not found\n");

return 0;
}