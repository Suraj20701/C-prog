#include <stdio.h>
#include <stdlib.h>
typedef struct node *NODE;
struct node
{
    int data;
    struct node *link;
};

NODE head = NULL;

NODE createNode(int data)
{
    NODE new_node = (NODE)malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("Insufficient memory");
        return NULL;
    }
    new_node->data = data;
    new_node->link = NULL;
    return new_node;
}

void insert_first(int data)
{
    NODE new_node = createNode(data);
    if (head == NULL)
    {
        head = new_node;
        return;
    }
    new_node->link = head;
    head = new_node;
}

void insert_rear(int data)
{
    NODE new_node = createNode(data);
    if (head == NULL)
    {
        head = new_node;
        return;
    }
    NODE cur = head;
    while (cur->link != NULL)
    {
        cur = cur->link;
    }
    cur->link = new_node;
}

void inset_at(int index, int data)
{
    NODE cur = head, prev, nxt;
    NODE new_node = createNode(data);
    if (index == 0)
    {
        insert_first(data);
    }
    
    for (int i = 1; i < index; i++)
    {
        prev = cur;
        cur = cur->link;
    }
    prev->link = new_node;
    new_node->link = cur;
}

void delete_first()
{
    if (head == NULL)
    {
        printf("List Empty");
        return;
    }
    NODE temp = head;
    head = head->link;
    free(temp);
}

void delete_last()
{
    if (head == NULL)
    {
        printf("List Empty");
        return;
    }

    NODE cur = head;
    NODE prev;
    while (cur->link != NULL)
    {
        prev = cur;
        cur = cur->link;
    }
    prev->link = NULL;
    free(cur);
}

void delete_at(int index)
{
    if (index == 0)
    {
        delete_first();
    }

    NODE cur = head, prev, nxt;
    for (int i = 1; i < index; i++)
    {
        prev = cur;
        cur = cur->link;
        nxt = cur->link;
    }
    prev->link = nxt;
    free(cur);
}

void display()
{
    if (head == NULL)
    {
        printf("\nLIst is empty");
        return;
    }
    printf("\n");
    NODE cur = head;
    while (cur->link != NULL)
    {
        printf("%d --> ", cur->data);
        cur = cur->link;
    }
    printf("%d", cur->data);
}

void freeList()
{
}

int main(int argc, char const *argv[])
{
   
    return 0;
}
