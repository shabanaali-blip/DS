//4.Doubly linked list-Insertion, deletion,search:

#include <stdio.h>
#include <stdlib.h> 
struct node
{
    int data;
    struct node *prev;
    struct node *next;
}*top,*temp,*temp1,*temp2,*temp4;


void create()
{
    int item; 
    temp =(struct node *)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->next = NULL;
    printf("\n Enter value to node : ");
    scanf("%d", &item);
    temp->data=item;
    count++;
}
void insert1()
{
    if (top == NULL)
    {
        create();
        top = temp;
        temp1 = top;
    }
    else
    {
        create();
        temp->next = top;
        top->prev = temp;
        top = temp;
    }
} 
void insert2()
{
    if (top == NULL)
    {
        create();
        top = temp;
        temp1 = top;
    }
    else
    {
        create();
        temp1->next = temp;
        temp->prev = temp1;
        temp1 = temp;
    }
} 
void insert3()
{
    int pos, i = 2;
 
    printf("\n Enter position to be inserted : ");
    scanf("%d", &pos);
    temp2 = top;
 
    if ((pos < 1) || (pos >= count + 1))
    {
        printf("\n Invalid Entry\n");
        return;
    }
    if ((top == NULL) && (pos != 1))
    {
        printf("\n Empty list cannot insert other than 1st position");
        return;
    }
    if ((top == NULL) && (pos == 1))
    {
        create();
        top = temp;
        temp1 = top;
        return;
    }
    else
    {
        while (i < pos)
        {
            temp2 = temp2->next;
            i++;
        }
        create();
        temp->next = temp2->next;
        temp->prev = temp2;
        if(temp2->next!=NULL)
          temp2->next->prev = temp;
        temp2->next = temp;
    }
}
void delete()
{
    int i = 1, pos;
 
    printf("\n Enter position to be deleted : ");
    scanf("%d", &pos);
    temp2 = top;
 
    if ((pos < 1) || (pos >= count + 1))
    {
        printf("\n Position out of range to delete");
        return;
    }
    if (top == NULL)
    {
        printf("\nEmpty list");
        return;
    }
    else
    {
        while (i < pos)
        {
            temp2 = temp2->next;
            i++;
        }
        if (i == 1)
        {
            if (temp2->next == NULL)
            {
                printf("Node deleted from list");
                free(temp2);
                temp2 = top = NULL;
                return;
            }
        }
        if (temp2->next == NULL)
        {
            temp2->prev->next = NULL;
            free(temp2);
            printf("Node deleted from list");
            return;
        }
        temp2->next->prev = temp2->prev;
        if (i != 1)
            temp2->prev->next = temp2->next;
        if (i == 1)
            top = temp2->next;
        printf("\n Node deleted");
        free(temp2);
    }
    count--;
}
void display()
{
    temp2 = top;
    if (temp2 == NULL)
    {
        printf("List empty to display \n");
        return;
    }
    printf("\n Linked list elements  : ");
 
    while (temp2->next != NULL)
    {
        printf(" %d ", temp2->data);
        temp2 = temp2->next;
    }
    printf(" %d ", temp2->data);
}
void search()
{
    int item, count = 0;
    temp2 = top;
 
    if (temp2 == NULL)
    {
        printf("\n List empty to search for data");
        return;
    }
    printf("\n Enter value to search : ");
    scanf("%d", &item);
    while (temp2 != NULL)
    {
        if (temp2->data == item)
        {
            printf("\n Data found in %d position",count + 1);
            return;
        }
        else
             temp2 = temp2->next;
            count++;
    }
    printf("\n %d not found in list\n", item);
}
void main()
{
    int ch;
    top = NULL;
    temp = temp1 = NULL;
    printf("\n1.Insert at beginning\n2.Insert at end\n3.Insert at a position\n4.Delete from the given position\n5.Search for element\n6.Exit\n"); 
    while (1)
    {
        printf("\n Enter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert1();
            display();
            break;
        case 2:
            insert2();
            display();
            break;
        case 3:
            insert3();
            display();
            break;
        case 4:
            delete();
            display();
            break;
        case 5:
            search();
            break;
        case 6:
            exit(0);
        default:printf("\n Invalid Entry\n");
            break;
        }
    }
}