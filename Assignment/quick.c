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
  k = partation(a, low, high,is_asending);
  quick_sort(a, low, k-1, is_asending);
  quick_sort(a, k+1, high, is_asending);
  }
}

int main()
{
 int n, a[10], choice;
 printf("Enter the size of the array");
 scanf("%d",&n);
 for (int i = 0; i < n; i++)
 {
     scanf("%d",&a[i]);
 }

 printf("Enter options \n > (1) Quicksort in asending order. \n  > (2) Quicksort in desending order.\n > (3)Exit");
 scanf("%d", &choice);
 while (1)
 {
  switch (choice)
   {
   case 1 :
     quick_sort(a,0,n-1,1);
      break;

   case 2 :
     quick_sort(a,0,n-1,0);
     break;

    case 3 :
      return 0;
 
   default:
     printf("Enter valid option");
     break;
  }
 }
    return 0;
}




// int main(){
//   int n, a[5]={2,1,4,7,5};
//   printf("Asending order");
//   quick_sort(a, 0, 4, 0);
//   printf("Sorted array : \n");
//    for (int i = 0; i <5; i++)
//       {
//           printf("%d\t", a[i]);
//       }

    // // int choice;
    //  int n, a[10], choice;
    // printf("Enter the size of the array");
    //     scanf("%d",&n);
    // printf("Enter array element : ");
    // for (int i = 0; i < n; i++)
    // {
    //  scanf("%d",&a[i]);
    // }
  

    // while (1)
    // {
    //  printf("Enter options \n> (1) Quicksort in asending order. \n> (2) Quicksort in desending order.\n> (3)Exit\n>");
    //  scanf("%d", &choice);

    //  switch (choice)
    //  {
    //  case 1:
    //     printf("Quicksort in asen");
    //     break;

    //  case 2:
    //     printf("Quicksort in desen");
    //     break;

    //  case 3:
    //     printf("Thanks for usig");
    //     return 0;
    //     break;
     
    //  default:
    //      break;
//     //  }
//     // }
    
//  return 0;   
// }