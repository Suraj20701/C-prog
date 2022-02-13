//  C program to implement queue using arrays.

#include<stdio.h>
#include<stdlib.h>
#define QUEUE_SIZE 5

void insert_rear(int item, int Q[], int *rear){     
    Q[++(*rear)] = item;
}

void delete_front(int Q[], int *front){ 
 
  printf("The deleted itm id %d : ",Q[(*front)++]);
 
}

void display(int Q[],int rear, int front){
    for(int i=front; i<= rear; i++){
      printf("%d\t",Q[i]);
    }
}

int main(){
     int Q[QUEUE_SIZE], rear = -1,front=0,choice,item;

for(;;){
  printf("\n######### Choose a option ###########\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
  scanf("%d",&choice);

  switch(choice){
    case 1 :
        if(rear == QUEUE_SIZE -1){
            printf("QUEUE Overflow");
              break;       
            }
      printf("Enter the item want to insert\n");
      scanf("%d",&item);
      insert_rear(item,Q,&rear);
      break;
    
    case 2 :
       if(rear<front){
              printf("Queue Underflow");
               break;
       }
       delete_front(Q,&front);
      break;

    case 3 :
     if(rear<front){
              printf("Queue Underflow");
               break;
       }
      printf("The Queue is \n");
      display(Q,rear,front);
      break;

    case 4 :
      printf("option 4");
      exit(0);

    default:
      printf("Choose correct option");
  }
}
     

    return 0;
}
