//Set Operations
#include<stdio.h>
#include<stdlib.h>

int i,j,k,p,ch,n1,n2,set1[10],set2[10], set3[20],flag;
char wish;
void uni()
{
k=0;
for(i=0;i<n1;i++)
{
set3[k]=set1[i];
k++;
}
for(i=0;i<n2;i++)
{
flag=1;
for(j=0;j<n1;j++)
{
if(set2[i]==set1[j])
{
flag=0;
break;
}
}
if(flag==1)
{
set3[k]=set2[i];
k++;
}
}
p=k;
for(k=0;k<p;k++)
{
printf(" %d\n",set3[k]);
} 
}
void intersection()
{
    k=0;
for(i=0;i<n2;i++)
{
flag=1;
for(j=0;j<n1;j++)
{
if(set2[i]==set1[j])
{
flag=0;
break;
}
}
if(flag==0)
{
set3[k]=set2[i];
k++;
}
}
p=k;
for(k=0;k<p;k++)

{
printf(" %d\n",set3[k]); 
 
}
}
void dif()
{
    k=0;
for(i=0;i<n1;i++)
{
flag=1;
for(j=0;j<n2;j++)
{
if(set1[i]==set2[j])
{
flag=0;
break;
}
}
if(flag==1)
{
set3[k]=set1[i];
k++;
}
}
p=k;
for(k=0;k<p;k++)

{
printf(" %d\n",set3[k]); 
}
}
void main()
{
    
printf("Enter the size of set1\n");
scanf("%d",&n1);
printf("Enter the element of set1\n");
for(i=0;i<n1;i++)
scanf("%d",&set1[i]);
printf("Enter the size of set2\n");
scanf("%d",&n2);
printf("Enter the elements of set2\n");
for(i=0;i<n2;i++)
scanf("%d",&set2[i]);
printf("1.Union\n 2.Intersection\n 3.Subtraction\n4.Exit\n");
while(1)
{
printf("Enter your choice");
scanf("%d",&ch);
switch(ch)
{
case 1:uni();
       break;
case 2: intersection();
       break;
case 3:dif();
       break;
case 4:exit(1);
default:printf("Invalid Entry\n");
}
}
}