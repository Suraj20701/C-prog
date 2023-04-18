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


/***** POINTER TO FUNCTION  *****/

// Function pointers in C are variables that can store the memory address of functions 
// And used in a program to create a function calls  pointed by them.
// 
// Syntax of Function Pointer in C
//    return_type (* pointer_name) (datatype_arg_1, datatype_arg_1, ...);
//      - return_type is return type of function
//      - pointer_name is name of variable
//      - in parameter list we have to mention the data type of parameters// 
//      eg.
//          float foo (int, int);    Declaration of a function pointer in C for the function foo will be           
//          float (*foo_pointer) (int, int);  function pointer declaration
// 
// Assigining value to function pointer
//        int (*pointer) (int); // function pointer declaration
//        int areaSquare (int); // function declaration
//        pointer = areaSquare; // Assign the function to function pointer
// 
// Calling function using pointer
//        int area = (*pointer)(length);
// e.g
      /*
      #include<stdio.h>

      // function declaration
      int areaRectangle(int, int);

      int main() {
          int length, breadth, area;

          // function pointer declaration
          int (*fp)(int, int); 

          printf("Enter length and breadth of a rectangle\n");
          scanf("%d%d", &length, &breadth);

          // pointing the pointer to functions memory address
          fp = areaRectangle;

          // calling the function using function pointer
          area = (*fp)(length, breadth); 

          printf("Area of rectangle = %d", area);
          return 0;
      }

      // function definition 
      int areaRectangle(int l, int b) {
          int area_of_rectangle = l * b;
          return area_of_rectangle;
      }

      */



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



/** STRUCTURES **/

/*****
 
 # Structure is a user-defined datatype in C which is a collection of homogeneous
  or heterogeneous elements.
 # These elements are grouped together under a single name for convenient handling. 
 # Structures help to organize complicated data, particularly in large programs.
 # It helps to construct a complex data type which is more meaningful.
 # In structure, data is stored in form of records.
 # Definig a structure
   - struct keyword is used to define a structure. struct defines a new data type which is a 
     collection of primary and derived data types.
      Syntax:
             struct [structure_tag]             
             {
             //member variable 1             
             //member variable 2             
             //member variable 3 ...
             
             }[structure_variables];
       - strucure_variables are the variables of type strucure_tag
      e.g struct Student
          {          
            char name[10];          
            int age;          
            char branch[5];          
            char gender;          
          };
    - Here struct Student declares a structure to hold the details of a student which consists of
      4 data fields, namely name, age, branch and gender. These fields are called as 
      structure elements or members.
    - Each member can have different data type, like in this case, name is an array of char type
      and age is of int type etc. Student is the name of the structure and 
      is called as the structure tag.
    - Size of the structure is 20 bytes no space is reserved for the above structure.Memory is 
      reserved only if the above definition is associated with variable.
    - Structure variable declaration
        struct Student student1, student2
         Here student1 and student2 are the structure varibales of type Student

    # Structure initialisation
       struct Student
          {          
            char name[10];          
            int age;          
            char branch[5];          
            char gender;          
          }student1 = {"Raju", 20, "CS", 'M'};
           
             or 
         struct Student
          {          
            char name[10];          
            int age;          
            char branch[5];          
            char gender;          
          };
         student1 = {"Raju", 20, "CS", 'M'};
        
    # Accessing Structures
        - Structures memers can be accessed using member operator i.e (.)
        - It can be also done using strucure poiner operator i.e (->)   
    
   
****/


// #include<stdio.h>
// struct Student
// {
//    char name[20];
//    int roll;
//    float percentage;
// };

// int main(int argc, char const *argv[])
// {
//     struct Student student={"Raju", 1, 89.4};
//     struct  Student *ptr;
//     ptr = &student;
//     printf("Roll NO : %d\nName : %s\nPercentage : %f", ptr->roll,ptr->name,ptr->percentage);
//     printf("\nEnter student detail \n");

//     scanf("%d%s%f", &ptr->roll, &ptr->name, &ptr->percentage);
//     printf("Roll NO : %d\nName : %s\nPercentage : %f", ptr->roll,ptr->name,ptr->percentage);
   
//     return 0;
// }


// Array of structures

// #include<stdio.h>

// struct Student
// {
//    char name[20];
//    int roll;
//    float marks;
// };
// int main(int argc, char const *argv[])
// {
//     int studentCount = 3;
//     struct Student students[studentCount];
//     for (int i = 0; i < studentCount; i++)
//     {
//         students[i].roll = i;
//         printf("Enter Name and Marks of student %d", i);
//         scanf("%s%f", students[i].name, &students[i].marks);
//     }

//        for (int i = 0; i < studentCount; i++)
//     {
//         printf("%s%f", students[i].name, &students[i].marks);
//     }
//     return 0;
// }



// Structure to find area of ractangle
// #include<stdio.h>
// struct Rectangle
// {
//     int length, breadth;
// };

// int main(int argc, char const *argv[])
// {
//     struct Rectangle r;

//     printf("Enter the length  and breadth of rect : ");
//    scanf("%d%d", &r.length, &r.breadth);
//     printf("Area = %d", r.length * r.breadth);
//     return 0;
// }



// #include<stdio.h>
// #include<string.h>

// struct Student
// {
//     int age;
//     char name[20];
//     char branch[10];
//     char gender;
// };

// int main(int argc, char const *argv[])
// {
//     struct Student s1;
//     strcpy(s1.name, "Suraj");
//     s1.age = 20;
//     s1.gender = 'M';
//    strcpy(s1.branch, "CS");
//     printf("Name : %s\nAge : %d\nBranch : %s\nGender : %c\n ", s1.name, s1.age, s1.branch, s1.gender);
//     return 0;
// }




// #include<stdio.h>
// #include<string.h>

// struct Student
// {
//     int age;
//     char name[20];
//     char branch[10];
//     char gender;
// };

// int main(int argc, char const *argv[])
// {
//     struct Student s1;
//     strcpy(s1.name, "Suraj");
//     s1.age = 20;
//     s1.gender = 'M';
//    strcpy(s1.branch, "CS");
//     printf("Name : %s\nAge : %d\nBranch : %s\nGender : %c\n ", s1.name, s1.age, s1.branch, s1.gender);
//     return 0;
// }


