//Disjoint Sets
#include<stdio.h>
char Bs2[9]="";
char Bs1[9]="";
char UN[9]="",IN[9]="",DI[9]="";

 void bitStringCreation(int U[],int S1[],int S2[],int k)
 {
	 int ii=0,j=0,i=0;
	 for(i=0;i<k;i++)
	 {
		   if(U[i]==S1[ii])
		    {
				ii++;
				Bs1[i]='1';
			}
			else
			{
				Bs1[i]='0';
			}
	 }
	  Bs1[i]='\0';
	 ii=0;
	 for(j=0;j<k;j++)
	 {
		    if(U[j]==S2[ii])
		    {
				ii++;
	        	Bs2[j]='1';
			}
			else
			{
				Bs2[j]='0';
			}
	  }	
	  Bs2[j]='\0'; 
     printf("Bit String of Set1= %s",Bs1);
     printf("\n\nBit String of Set2= %s",Bs2);
     
 } 
 
void Union(int k)
{
	int i;
	for(i=0;i<k;i++)
	{
	 UN[i]=((Bs1[i]-'0')|(Bs2[i]-'0'))+'0';
    }
     UN[i]='\0';
	printf("UNION = %s\n",UN);

}
void Intersection(int k)
{
	int i;
	for(i=0;i<k;i++)
	{
	 IN[i]=((Bs1[i]-'0')&(Bs2[i]-'0'))+'0';
    }
     IN[i]='\0';
	printf("INTERSECTION = %s\n",IN);
}
void Difference(int k)
{
	int c,j;
	char Comp[9]="";
	printf("\npress 1:Set1-Set2,2:Set2-Set1\nEnter your Choice =");
	scanf("%d",&c);
	if(c==2)
	{
		for(int i=0;i<k;i++)
		{
			Comp[i]=(Bs1[i]=='1')?'0':'1';
		}
	for(j=0;j<k;j++)
	{
	 DI[j]=((Bs2[j]-'0')&(Comp[j]-'0'))+'0';
    }
     DI[j]='\0';
	}
	else
	{
	for(int i=0;i<k;i++)
		{
			Comp[i]=(Bs2[i]=='1')?'0':'1';
		}
		
	for(j=0;j<k;j++)
	{
	 DI[j]=((Bs1[j]-'0')&(Comp[j]-'0'))+'0';
    }
     DI[j]='\0';
   }
   	printf("DIFFERENCE = %s\n",DI);
}
		
int main()
{
   int ch,i=0,n1,n2,j,S1[10],S2[10];
   int U[]={1,2,3,4,5,6,7,8}; 
   printf("Enter the number of values of set1(U=1-8):\t");
   scanf("%d",&n1);
   printf("Enter the elements:\n");
   for(i=0;i<n1;i++)
    scanf("%d",&S1[i]);
   printf("Enter the number of values of set2(U=1-8):\t");
   scanf("%d",&n2);
   printf("Enter the elements:\n");
   for(j=0;j<n2;j++)
    scanf("%d",&S2[j]);
   i=sizeof(U)/4;   
   bitStringCreation(U,S1,S2,i);
   printf("1-Union \n2->Intersection \n3->Difference \n4->Exit\n");
   while(1)
	{
	printf("Enter your choice:\n");
	scanf("%d",&ch);
	switch(ch)
	{
	  case 1:Union(i);
	         break;
	  case 2:Intersection(i);
	         break;
	  case 3:Difference(i);
	         break;
	  case 4:return 0;
	         break;	
      default:printf("Invalid Entry\n");
	}
   }
 }