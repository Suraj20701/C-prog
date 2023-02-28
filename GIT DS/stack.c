#include <stdio.h>
#define size 5
int stack[size];
int top = -1;
void push();
void pop();
void peak();
void display();
int main(int argc, char const *argv[])
{
    int choice;
    while (1)
    {
        printf("\n\n(1)PUSH\n(2)POP\n(3)PEAK\n(4)DISPLAY\n(0)EXIT");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {

        case 0:
            return 0;
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peak();
            break;
        case 4:
            display();
            break;

        default:
            printf("\nInvalid option");
            break;
        }
    }
    return 0;
}

void push()
{
    if (top == size - 1)
    {
        printf("Stack is overflow\n");
        return;
    }
    printf("Enter the element to push : ");
    scanf("%d", &stack[++top]);
}

void pop()
{
    if (top == -1)
    {
        printf("\nStack is underflow");
        return;
    }
    printf("\nThe popped element is %d ", stack[top--]);
}

void display()
{
    if (top == -1)
    {
        printf("Stack is underflow\n");
        return;
    }
    printf("\n\nThe stack elements are : \n");
    for (int i = top; i > -1; i--)
        printf("%d\n", stack[i]);
}

void peak()
{
       if (top == -1)
    {
        printf("Stack is underflow\n");
        return;
    }

    printf("Peak element is ", stack[top]);

}
