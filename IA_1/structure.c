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

