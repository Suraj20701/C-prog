//  C program to illustrate Stack operations using arrays.

#include<stdio.h>
#include<stdlib.h>
#define STACK_SIZE 5

// # Push operations
void push(int item, int stack[], int *top){
    
    if(*top == STACK_SIZE - 1){
        printf("Not enough space to push an item");
        return;
    }   
    stack[++(*top)] = item;
    printf("The added item is : %d", item);
    return;
}

// # Pop operations
void pop(int stack[], int *top){

    if(*top == -1){
        printf("Opps! No items to delete");
        return;
    }
    printf("The Deleted item is : %d",stack[*top]);
   (*top)--;
    return;
}

// # Display operations
void display(int stack[], int top){
    int i;
    if( top == -1){
        printf("The stack is empty nothing to display");
        return;
    }
  printf("\n############ Stack #############\n");
    for(i=0;i<=top;i++){
        printf("%d\n",stack[i]);
    }
    return;
}

int main(){
    
    int item,choice,top=-1,stack[STACK_SIZE];
 
    for(;;){
        printf("\n######## PLEASE ENTER YOUR CHOICE ########\n\t1.PUSH\n\t2.POP\n\t3.DISPLAY\n\t4.EXIT\n");
        scanf("%d",&choice);

        switch(choice){
            case 1 : 
                printf("Enter the item that wants to push\n");
                scanf("%d",&item);
                push(item,stack,&top);
                break;

            case 2 :
                pop(stack,&top);
                break;

            case 3 :
                display(stack,top);
                break;

            case 4 :
                exit(0);

            default :
                printf("Please enter the valid voice");

        }

        printf("Top : %d  stack : ",top);
        for(int i=0; i<STACK_SIZE; i++){
            printf("\t%d",stack[i]);
        }
    }

    return 0;
}