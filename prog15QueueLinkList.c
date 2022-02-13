#include<stdio.h>
#include<stdlib.h>
#define null 0

struct queue{
  int value;
  struct queue *link;
  };
  
  struct queue *front=null;
  struct queue *rear=null;

void insert_rear(int value){
 struct queue *ptr;
 ptr=(struct queue*)malloc(sizeof(struct queue));
 ptr->value=value;
 ptr->link=null;
 if(front==null&&rear==null){
    printf("This is the first node\n");
    front=rear=ptr;
    }
 else{
   rear->link=ptr;
   rear=ptr;
  }
}

void delete_front(){
  struct queue *ptr;
  int item;
  if(front==null){
    printf("Queue is empty\n");
    return;
    }
  ptr=front;
  front=front->link;
  item=ptr->value;
  printf("Deleted data is %d\n",item);
}

void display(){
 struct queue *ptr;
  ptr=front;
 if(front==null){
    printf("Queue is empty\n");
    return;
   }
 printf("The elements of queue are\n");
 while(ptr!=null){
    printf("%d\n",ptr->value);
    ptr=ptr->link;
   }
}

int main()
{
 int item,choice;
 while(1){
 printf("*******QUEUE MENU******\n");
 printf("1.Insert rear\n2.Delete front\n3.Display\n4.Exit\n");
 printf("Enter your choice\n");
    scanf("%d",&choice);

 switch(choice){
    case 1:printf("Enter the item to be inserted\n");
        scanf("%d",&item);
        insert_rear(item);
        break;
    
    case 2:delete_front();
        break;
    
    case 3:display();
        break;
    
    case 4:exit(0);
    
    default:printf("Invalid choice\n");
     }
  }
}


