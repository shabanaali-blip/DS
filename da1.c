//1.Program to merge two sorted array:


#include<stdio.h>

int main()

{

int a[10],b[10],c[20],i,j,n,m,k;

printf("Enter the number of elements in first array:\t");

scanf("%d",&n);

printf("Enter the sorted elements:\t");

for(i=0;i<n;i++)

{
    
scanf("%d",&a[i]);

}

printf("Enter the number of elements in second array:\t");

scanf("%d",&m);

printf("Enter the sorted elements:\t");

for(j=0;j<m;j++)

{
    
scanf("%d",&b[j]);

}

printf("Array after merging two array:\n");

i=j=k=0;

while(i<n && j<m)

{
    
if (a[i]<b[j])
     
c[k++]=a[i++];
    
else
     
c[k++]=b[j++];

}

if(j>=m)

{
    
while(i<n)
    
{
    
c[k++]=a[i++];
    
}

}

if(i>=n)

{
    
while(j<m)
    
{

c[k++]=b[j++];
    
}

}


for(i=0;i<n+m;i++)

{
    
printf("%d",c[i]);
  
  printf("\t");

}

}