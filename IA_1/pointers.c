/*
*                           Pointers and stack
*  Introduction to Pointers, Pointers and Arrays. Introduction to Structures, Declaration, 
*  Initialization. Stack and its Operations, Stack application: conversion from infix to postfix
*
*/

/** POINTERS **/ 

/*********
 
   # A pointer is a variable that contains the address of a another variable variable. The actual value of pointer
     is address of memory.
   # The general form of a pointer variable declaration is −
        type *var-name; type* var-name; type *var-name;
           - type is the pointer's base type; it must be a valid C data type
           - var-name is the name of the pointer variable.
   # For any datatype T there is corresponding type pointer to T
   # Two important operators used with pointers are
        & the address operator
        * dereferencing or indirection operator 
      eg. If we have declaration
         int i, *p;
             - i is a integer variable 
             - p is pointer to integer
         p = &i;
             - &i returns the address of i and assign to the pointer variable p
         - To access the value of i using pointer we has to use dereferencig operator
              i.e  *p  // 10 
              - *p refers to integer at the location referenced by the pointer  

***********/

// #include<stdio.h>

// int main(int argc, char const *argv[])
// {
//     int num, *ptr;
//     float float_num = 5.6, *float_ptr = &float_num;
//     char my_char = 'a', *char_ptr = &my_char;
//     num = 10;
//     ptr = &num;
//     printf("The valriable num = %d is stored at address %x\n", *ptr, ptr);
//     printf("The valriable float_num = %1.2f is stored at address %x\n", *float_ptr, float_ptr);
//     printf("The valriable char = %c is stored at address %x", *char_ptr, char_ptr);
//     return 0;
// }


/** ARTHEMATIC OPERATIONS USING POINTER **/

// #include<stdio.h>

// int main(int argc, char const *argv[])
// {
//     int num1 = 10, num2 = 15;
//     int *num1_ptr = &num1, *num2_ptr = &num2;
//     printf("Additon of %d,%d is ", *num1_ptr + *num2_ptr);
//     printf("Substraction of %d,%d is ", *num1_ptr + *num2_ptr);
//     printf("Multiplication of %d,%d is ", *num1_ptr + *num2_ptr);
//     printf("Division of %d,%d is ", *num1_ptr + *num2_ptr);
//     return 0;
// }

/** NULL POINTER **/

/******
 
 # A pointer that is assigned NULL is called a null pointer.
 # A NULL pointer is defined as a special pointer value that points to ‘\0’ in the memory.
 # It is always a good practice to assign a NULL value to a pointer variable incase you
  do not have an exact address to be assigned.
 # This is done at the time of variable declaration.
 # The NULL pointer is a constant with a value of zero defined in several
   standard libraries

********/

// #include<stdio.h>

// int main(int argc, char const *argv[])
// {
//     int *null_ptr = NULL;
//     if (null_ptr == NULL)
//     {
//         printf("This pointer pointing to NULL");
//     }
//     int num = 10;
//      null_ptr = &num;
//     if (null_ptr )
//     {
//         printf("\nPointer pointing at %x cantains value %d", null_ptr, *null_ptr);
//     }    
        
//     return 0;
// }


/** Single vaiable to multiple pointers **/

// #include<stdio.h>
// int main(int argc, char const *argv[])
// {
//   int a = 10;
//   int *p = &a, *q = &a, *r = &a;
//   printf(" *p = %d\n *q = %d\n *r = %d", *p, *q, *r);
//   return 0;
// }

/** Swapping of variables using **/
// #include<stdio.h>

// void swap(int *, int *);

// int main(int argc, char const *argv[])
// {
//     printf("Command line %d %d\n", argc);
//     int a= 10, b = 20;
//     printf("Before swaping a = %d  b = %d", a, b);
//     swap(&a, &b);
//     printf("\nAfter swaping a = %d  b = %d", a, b);
//     return 0;
// }

// void swap(int *p, int *q)
// {
//     int temp = *p;
//     *p = *q;
//     *q = temp;
// }


/** Smallest of two num using pointer function returning pointer **/

// #include<stdio.h>
// int* smallest(int *, int *);
// int main(int argc, char const *argv[])
// {
//     int a=5, b=10;

//     printf("The smallest in %d and %d is %d", a, b,  *smallest(&a, &b));
//     return 0;
// }

// int* smallest(int * a, int *b)
// {
//   return  (*a < *b)? a:b;
// }

/** Pointers to pointers **/

// Pointer to pointer
// Maximum level
//  According to ANSI C, each compiler must have at least 12 levels of pointers. 
//  This means we can use 12 * symbols with a variable name.
//  Level of pointers or say chain can go up to N level depending upon the memory size.

// #include <stdio.h>

// int main(int argc, char const *argv[])
// {
//     int a = 10;
//     int *ptr1 = &a;
//     int **ptr2 = &ptr1;
//     int ***ptr3 = &ptr2;

//     printf("Value of a1 = %d, a2 = %d, a3 = %d ", *ptr1, **ptr2, ***ptr3 );
//     return 0;
// }



