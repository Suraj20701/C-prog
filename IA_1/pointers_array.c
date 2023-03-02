/***  ARRAYS ***/
/*****

 # Arrays in C are the collection of homogeneous elements.

 # Continuous memory locations are allocated for array elements by the compiler.

 # Searching an array for an individual element can be very efficient, addition
   and deletion of elements are complex and inefficient processes.

 # Pointer to array are given as
    int a[5] = {10, 20, 30, 40, 50}, *ptr;
    - Here a is an integer array containing 5 elements
    - And ptr is a integer pointer then array can be pointed by
        ptr = a;  //a stores its base address(location of the first element of the array i.e &a[0])
          or
        ptr = &a[0];

  # Every value of array can be accessed by using p++
        for (int i = 0; i < 5; i++)
         {
           printf("%d\n", *(ptr++));
         }

  # Address of an array element is calculated using its index and the scale factor of data type
    i.e Address of a[3]= base address+(3*scale factor of int)
        - scale facor is the size (or length) of that datatype

  # Instead of using array indexing pointer can be used to access array
         *(ptr+3) gives value of a[3]

  # Access array elemts using pointer is given as below
      for (int i = 0; i < 5; i++)
        {
            printf("%d\t", *(a+i));
        }


*************/

//  program for pointers and array
// #include<stdio.h>

// int main(int argc, char const *argv[])
// {
//     int a[5] = {10, 20, 30, 40, 50},  *ptr;
//     ptr = a;

//     for (int i = 0; i < 5; i++)
//     {
//        printf("%d\t", *(a+i));
//     }

//     return 0;
// }

// #include <stdio.h>
// int main(int argc, char const *argv[])
// {
//     int a[5], *ptr;
//     printf("\nEnter the array elements ");
//     for (int i = 0; i < 5; i++)
//         scanf("%d", &a[i]);

//     printf("\nThe array elements ");

//     for (int i = 0; i < 5; i++)
//         printf("%d ", a[i]);

//     ptr = a;

//     printf("\nEnter the array elements ");
//     for (int i = 0; i < 5; i++)
//         scanf("%d", ptr + i);

//     printf("\nThe array elements ");
//     for (int i = 0; i < 5; i++)
//         printf("%d ", *(ptr + i));

//     // ADDS i to *ptr i.e a[0]
//     // printf("\nThe array elements ");
//     // for (int i = 0; i < 5; i++)
//     // {
//     //     printf("%d ", *ptr+i);
//     // }

//     return 0;
// }

// #include <stdio.h>
// void display(int *p)
// {
//     printf("Array elements are : ");
//     for (int i = 0; i < 6; i++)
//     {
//         printf("%d ", *(p+i));
//     }

//     printf("\na[0] : %d \n", *p);
//     printf("a[3] : %d\n", *(p + 3));
// }

// int main(int argc, char const *argv[])
// {
//     int a[6] = {1, 2, 3, 4, 5, 6};
//     display(a);
//     return 0;
// }

/** Array of characters **/

// #include<stdio.h>
// int main(int argc, char const *argv[])
// {

//     char *s[] = {"gate", "gatesmashers", "varun", "tranding"};

//     printf("String %s \n", *s+1);
//     printf("String %s \n", *(s+2));
//     printf("String %s \n", (*(s+1)+4));
//     return 0;
// }

// #include<stdio.h>

// int main(int argc, char const *argv[])
// {
//     static char *s[] = {"black", "white", "pink", "voilet"};
//     char **ptr[] = {s+3, s+2, s+1, s};
//     char ***p;
//     p=ptr;
//     ++p;
//     printf("%s", **p+1);

//     return 0;
// }
