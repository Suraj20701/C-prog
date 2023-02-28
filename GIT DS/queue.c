#include<stdio.h>
#define size 5

int queue[5], front = 0, rear = -1;

void enqueue(int data)
{
    if( rear == size - 1 )
    {
        printf("\nqueue is full");
        return;
    }
    queue[++rear] = data;
}

void dequeue()
{
    if (rear < front)
    {
        printf("\nQueue is empty");
        return;
    }
        printf("\nThe removed elemnt is %d\n", queue[front++]);
    
}

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
