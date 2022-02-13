//  C program to implement  circular queue using arrays.

#include<stdio.h>
#include<stdlib.h>
#define QUEUE_SIZE 3

void insert_rear(int item, int Q[], int *count, int *rear){
    (*rear) = ((*rear)+1) % QUEUE_SIZE;
    Q[(*rear)] = item;
    (*count)++;
}

void delete_front(int Q[],int *count, int *front){
    printf("The deleted item is %d",Q[(*front)]);
    (*front) = (*front + 1) % QUEUE_SIZE;
    (*count)--;
}

void dispaly_Queue(int Q[],int count, int front){
    for(int i=0;i<count;i++){
        printf("%d\t",Q[front]);
           front = (front + 1) % QUEUE_SIZE;
    }
}


int main(){
  int Q[QUEUE_SIZE],item,choice,rear = -1, front =0,count=0;

  for(;;){
      printf("\n####### Choose Option ########\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
      scanf("%d",&choice);

      switch(choice){
          case 1:
            if(count == QUEUE_SIZE){
                printf("Opps!! Queue overflow\n");
                break;
            }
            printf("Enter the item : ");
            scanf("%d",&item);
            insert_rear(item,Q,&count,&rear);
            break;

          case 2 :
            if(count == 0){
                printf("Queue underflow\n");
                break;
            }
                delete_front(Q,&count,&front);
            break;

          case 3 :
             if(count == 0){
                printf("Queue underflow\n");
                break;
            }
            dispaly_Queue(Q,count,front);
            break;

            case 4:
                exit(0);

        case 5:
            for(int i =0; i<QUEUE_SIZE; i++){
                printf("%d\t",Q[i]);
            
            }
      }
  }
    return 0;
}