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
