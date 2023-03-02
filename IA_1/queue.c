/***  QUEUE   ****/
/**
 
 # It is an ordered group of homogeneous  elements.

 # Queues have two ends:
    - Elements are added at one end.(rear)
    - Elements are removed from the other end.(front)
 # The element added first is also removed first (FIFO: First In, First Out).
 
 */


/** QUEUE IMPLEMENTATION **/

#include<stdio.h>
#define size 5

int queue[5], front = 0, rear = -1;
/*
   ALGORITHM : enqueue(data)
   declare queue[size] front = 0 rear = -1
   if rear = size - 1
      display message queue is full
      return
   end if
   increment rear by 1
   assign queue[rear] = data

*/
void enqueue(int data)
{
    if( rear == size - 1 )
    {
        printf("\nqueue is full");
        return;
    }
    queue[++rear] = data;
}

/*
if rear < front 
   display message queue is empty
   return
end if
removed_element = queue[front]
incement the front


*/

void dequeue()
{
    if (rear < front)
    {
        printf("\nQueue is empty");
        return;
    }
        printf("\nThe removed elemnt is %d\n", queue[front++]);
    
}
/*
if rear < front 
   display message queue is empty
   return
end if
for i = front i<=rear i++
  print the elemnt queue[i]
end for

end of algorithm

*/
void display()
{
    if(rear < front)
    {
        printf("queue is empty");
        return;
    }
    printf("\n Queue elemts are : \n");
    for (int i = front; i <= rear; i++)
    {
        printf("%d\t", queue[i]);
    }
    
}

int main(int argc, char const *argv[])
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);
    display();


    dequeue();
    dequeue();
      dequeue();
    dequeue();  dequeue();
    dequeue();

    display();
    return 0;
}
