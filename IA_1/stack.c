/** Stack and its application **/
/*********
 
  # Stack is an ordered list of homegeneous elements in which the insertion and deletion
     of elements are made at only one end called as top

  # The insert operation called as push

  # The deletion operation called as pop

  # In stack the last inserted element is the element first removed so stack is known as
    Last-In-First-Out(LIFO) or First-In-Last-Out(FILO)

  # Stack also called as pushdown store.

  # Applications of stack 
     - Infix expression Evaluation
     - Postfix expression Evaluation
     - Infix to postfix Conversion
  
  # Stack operations
    - push()
        - Inserting an element into the stack is called push operation.
        - Only one item is inserted at a time and item has to be inserted only 
           from top of the stack
        - When elements are being inserted there is possibilty of stack being full.Trying
         to insert an element when stack is full results in overflow of stack

    - pop()
        - In any item is delete from top of the stack stack top will be decreased by 1.
        - If the stack is empty and you are trying to pop the element results in inderflow
          of stack

    - peak()

    - display()


*********/
/** Implent stack using array **/

// #include <stdio.h>
// #define size 5
// int stack[size];
// int top = -1;

// /****
//  * Algorithm : push(int data)
//  * 
  
//   if top = size -1
//   show stack overflow 
//   return from the function

//   else increment the top by 1
//   stack[top] = data  
  
  
//  * 
//  * 
// ****/

// void push(int element)
// {
//     if (top == size - 1)
//     {
//         printf("Stack is overflow\n");
//         return;
//     }
//     stack[++top] = element;
// }

// /***
//  * 
//  * 
//   if top = -1
//   show stack underflow message

//   else access stack[top] element for further operation
//   decement top by 1
//  *
//  * 
// */
// void pop()
// {
//     if (top == -1)
//     {
//         printf("\nStack is underflow");
//         return;
//     }
//     printf("\nThe popped element is %d ", stack[top--]);
// }


// /***
//  *
 
//   if top = -1
//   show stack underflow message

//   else iterate from i = top to i =-1
//   display  stack[i]

// */
// void display()
// {
//     if (top == -1)
//     {
//         printf("Stack is underflow\n");
//         return;
//     }
//     printf("\n\nThe stack elements are : \n");
//     for (int i = top; i > -1; i--)
//         printf("%d\n", stack[i]);
// }

// void peak()
// {
//        if (top == -1)
//     {
//         printf("Stack is underflow\n");
//         return;
//     }

//     printf("Peak element is ", stack[top]);

// }

// int main(int argc, char const *argv[])
// {
//    push(10);
//    push(20);
//    push(30);
//    display();
//    pop();
//    pop();
//    display();
//    return 0;
// }

/** Postfix evaluation **/ 

/***
 *  Algorithm : postfix_evaluation(char[] expression)
 * 
 *Create a stack to store operands (or values). 
    Scan the given expression from left to right and do the following for every scanned element. 
If the element is a number, push it into the stack 
If the element is an operator, pop operands for the operator from the stack. Evaluate the operator and push the result back to the stack 
When the expression is ended, the number in the stack is the final answer                                                                               
 * 
 *     
 *    
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define size 20
int stack[size];
int top = -1;


void push(int element){
    if (top==size-1)
    {
        printf("Stack overflow");
        exit(0);

    }
    stack[++top] = element;
}

int pop(){
    int pop_elmt = stack[top--];
   return pop_elmt; 

}

int main(int argc, char const *argv[])
{
    char expression[20];
  printf("Enter the expression\n");
  scanf("%s",expression);

  for (int i = 0; expression[i] != '\0'; i++)
  {
    if(expression[i]>=48 && expression[i]<=57)
    {
        push(expression[i]-48);
    }
    else
        {
            int num1 = pop();
                int num2 =  pop();
            switch (expression[i])
            {
            case '+':
               push(num1 + num2);
                break;
             case '-':
               push(num1 - num2);
                break;
             case '*':
               push(num1 * num2);
                break;
            }
    }
    
    
  }
  printf("Evaluation is %d", stack[top]);
    
    return 0;
}
