//3.Singly linked stack- Push,pop,linear search:

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
}*top,*temp,*top1;
 void push(int item)
    {
        if(top==NULL)
        {
            top=(struct node *)malloc(sizeof(struct node));
            top->data=item;
            top->next=NULL;
        }
        else
        {
            temp=(struct node *)malloc(sizeof(struct node));
            temp->next=top;
            temp->data=item;
            top=temp;
        }
        
    }
     void pop()
    {
        if(top==NULL)
        {
            printf("Stack is empty\n");
        }
        else
        {
            temp=top;
            printf("Element popped is %d \n",top->data);
            top=top->next;
            temp->next=NULL;
            free(temp);
        }
    }
    
    void display()
    {
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    temp=top;
    printf("Stack elements are :\n");
    while(temp!=NULL)
    {
        printf("%d \t", temp->data);
        temp = temp->next;
    }
    printf("\n");
    }
    
    void search(int x)
    {
        int i=0,c=0;
        if(top==NULL)
        {
            printf("Stack is empty\n");
        }
        else
        {
        for(temp=top;temp!=NULL;temp=temp->next)
        {  
            if(temp->data==x)
            {
                c=1;
                printf("Item found at position %d \n",i);
                break;
            }
            i++;
            if(c==0)
            {
                printf("Item not found\n");
            }
        }}
    }
int main()
{
    int ch,item,x;
    printf("Stack Using Linked List:\n");
    printf("\n1.Push\n2.Pop\n3.Search\n4.Display\n5.Exit\n");
    while(1)
    {
        printf("Enter your choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the element to be pushed:\n");
                scanf("%d",&item);
                push(item);
                break;
            case 2:pop();
                break;
            case 3:  printf("Enter the item to be searched:\n");
                scanf("%d",&x);
                  search(x);
                break;
            case 4:display();
                break;
            case 5: 
                exit(1);
            default:printf("Invalid Entry\n");
        }
    
}
}
