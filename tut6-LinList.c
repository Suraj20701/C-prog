//  C program to implement singly linked list: insert, delete, search and display.

#include<stdio.h>
#include<stdlib.h>
struct  LinkedList
{
    int data;
    struct LinkedList *next;
};
typedef struct LinkedList * node;

node getNode()
  { 
      node temp;
       temp=(node)malloc(sizeof(struct LinkedList));
       if(temp==NULL)
      {
          printf("Memory insufficient");
          exit(1);
     }
     temp->next=NULL;
      return temp;
 }
   
void freeNode(node temp)
{
      free(temp);
}

node insert_front(int item, node first)
{
     node temp;
     temp=getNode();
    temp->data=item;
    if(first==NULL) 
      first=temp;
else
 {
    temp->next=first;
   first=temp;
}
 return first;
}

node insert_rear(int item, node first)
{
   node temp,cur;
    temp=getNode();
    temp->data=item;
    if(first==NULL)
         first=temp;
  else
  {
     cur=first;
     while(cur->next!=NULL)
     {
        cur=cur->next;
     }
    cur->next=temp;
}
return first;
}

node insert_random(int item,node first,int position)
{
    int i;
   node ptr,temp;
   ptr=getNode();
   ptr->data=item;
   if(position==1)
   {
       ptr->next=first;
        first=ptr;
    }
   else
   {
        temp=first;
       for(i=1;i<position-1;i++)
       {
            temp=temp->next;
        }
     ptr->next=temp->next;
     temp->next=ptr;
   }
  return first;
}

  node delete_front(node first)
{
    node cur;
     if(first==NULL)
    {
        printf("list is empty");
       return NULL;
   }
   cur=first;
    first=first->next;
    printf("The deleted item is %d\n", cur->data);
    freeNode(cur);
   return first;
}

node delete_rear(node first)
{
    node cur,prev;
   if(first==NULL)
   {
      printf("List is empty");
      return NULL;
    }
    prev=NULL;
     cur=first;
    while(cur->next!=NULL)
    {
          prev=cur;
          cur=cur->next;
}
prev->next=NULL;
printf("Deleted item is %d\n",cur->data);
freeNode(cur);
return first;
}

node delete_random(node first, int position)
{  
   node prev,cur;
  int i;
   if(first==NULL)
    {
        printf("List is empty");
        return NULL;
   }
   cur=first;
  if(position==1)
  {
     first=first->next;
     printf("Deleted item is %d\n", cur->data);
    freeNode(cur);
  }
  else
 {
    prev=NULL;
   for(i=1;i<position;i++)
    {
       prev=cur;   
       cur=cur->next;
   }
     prev->next=cur->next;
    printf("The deleted element is %d",cur->data);
    freeNode(cur);
}
return first;
}

void display(node first)
{
   node cur;
   if(first==NULL)
   {
    printf("List is empty");
   return;
}
cur=first;
while(cur!=NULL)
{   
    printf(" %d->",cur->data);
    cur=cur->next;
}
}
void search(node first, int key)
{
    node cur;
    cur=first;
     while(cur!=NULL)
    {
         if(cur->data==key)
         {
             printf("Search Successful");
             return;
        }
       cur=cur->next;
     }
    printf("Search Unsuccessful");
 }

int main()
{     
         node first=NULL;
          int choice,item,position,key;
         for(;;) 
         { 
                  printf("\n########### Menu ###########\n");
                  printf("1. Insert at the beginning of the list\n2. Insert at the end of the list\n");
                  printf("3. Insert at nth position\n4. Delete a node from the beginning\n");
                  printf("5. Delete a node from the end of the list\n6. Delete a specific node\n");
                  printf("7. Search a node\n8. Display\n9. Exit\n");
                  printf("Enter your choice:");
                  scanf("%d",&choice);
                  switch(choice)
                  {
                       case 1: printf("Enter the item to be inserted:");
                                    scanf("%d",&item);
                                     first=insert_front(item,first);
                                     break;
                    case 2: printf("Enter the item to be inserted:");
                                    scanf("%d",&item);
                                     first=insert_rear(item,first);
                                     break;
                   case 3:    printf("Enter the item to be inserted:");
                                    scanf("%d",&item);
		       printf("Enter the position");
                                    scanf("%d",&position);
                                       first=insert_random(item,first,position);
                                     break;
                   case 4: first=delete_front(first);
                                 break;
                    case 5: first=delete_rear(first);
                                 break;
                   case 6: printf("Enter the position ");
                                 scanf("%d",&position);
                                  first=delete_random(first,position);
                                 break;
              case 7:printf("Enter the key item to be searched:");
                            scanf("%d",&key);
                              search(first,key);
                            break;
              case 8: display(first);
                            break;
             case 9: exit(0);
              default : printf("Enter valid choice");
      }
   }
   
   return 0;
}
