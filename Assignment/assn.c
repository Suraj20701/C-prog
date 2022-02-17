#include<stdio.h>
void exchange(int *p, int *q){
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}

int partation(int a[], int low, int high, int is_asending){
     int piote, i, j;
     piote = low;
     i = low + 1;
     j = high;

     while (i<j)
     {
         if (is_asending)
         {
         while(a[i] <= a[piote]) i++;
         while(a[j] > a[piote]) j--; 
         }
         else
         {
         while(a[i] >= a[piote]) i++;
         while(a[j] < a[piote]) j--; 
         }
         
         
         if (i<j)
         {
             exchange(&a[i], &a[j]);
         }
     }

     exchange(&a[j],&a[piote]);
     
     return j;
}

void quick_sort(int a[], int low, int high, int is_asending){
  int k;
  if(low<high){
  k = partation(a, low, high, is_asending);
  quick_sort(a, low, k-1, is_asending);
  quick_sort(a, k+1, high, is_asending);
  }
}

void print_array(int a[],int last_index){
  int i;
  for (i = 0; i <= last_index; i++)
  {
      printf("%d\t",a[i]);
  }
  
}
int main(){

    int n, a[10], choice;
    change_input :
    printf("Enter the size of the array : ");
    scanf("%d",&n);
    
    printf("Enter array element : ");
    for (int i = 0; i < n; i++)
     scanf("%d",&a[i]);
    

    while (1)
    {
     printf("\n\nEnter options \n> (1) Quicksort in asending order. \n> (2) Quicksort in desending order.\n> (3)Change input (4)Quit\n>>>");
     scanf("%d", &choice);

     switch (choice)
     {
     case 1:
        printf("Array sorted in asending order : \n");
        quick_sort(a, 0, n-1,1);
        print_array(a,n-1);
        break;

     case 2:
        printf("Array sorted in desending order : \n");
        quick_sort(a, 0, n-1,0);
        print_array(a,n-1);
        break;

     case 3:
        goto change_input;
        break;

     case 4:
        printf("Thanks for usig");
        return 0;

     default:
         break;
     }
    }
    
 return 0;   
}