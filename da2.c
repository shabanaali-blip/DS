//2.Circular Queue-Add,Delete,Search:

#include <stdio.h>
#define max 5
int q[max],front=-1,rear=-1;
int main() 
{
   int ch;
   printf("C-Queue Operations:\n");
   printf("1.Insertion\n 2.Deletion\n 3.Search\n4.Exit\n");
   while (1)
   {
       printf("Enter your choice:\n");
       scanf("%d",&ch);
       switch(ch)
       {
           case 1: insert();
                   break;
           case 2: del();
                   break;
           case 3: search();
                   break;
           case 4:
                   exit(1);
           default:printf("Invalid Entry");
       }
   }
}
   void insert()
   {
       int item;
       if((front==0 && rear==max-1) || (front==rear+1))
       {
           printf("Queue is full\n");
       }
       else
       {
           printf("Enter the item to be inerted:\n");
           scanf("%d",&item);
           if(rear==max-1)
           {
               rear=0;
           }
           else if(rear==-1)
           {
               rear=0;
               front=0;
           }
           else
           {
               rear++;
           }
           q[rear]=item;
       }
   }
   void del()
   {
       if(front==-1)
       {
           printf("Queue is empty\n");
       }
       printf("Element deleted %d \n",q[front]);
       if(front==max-1)
       {
           front==0;
       }
       else if(front==rear)
       {
           front==-1;
           rear==-1;
       }
       else
       {
           front++;
       }
   }
void search()
{
    int i=0,c=0,item;
    printf("Enter the item you want to search:\n");
    scanf("%d",&item);
    for(i=front;i<=rear;i++)
    {
        if (item==q[i])
        {
            printf("Item found at position %d \n",i);
            c++;
        }
    }
    if(c==0)
    {
        printf("Item not found\n");
    }
    else
    {
        printf("Item found %d times\n",c);
    }
}