#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<time.h>

struct items{
char name[50];
float price;
int qty;
float avg;
}item[10],temp;
void main()
{
clrscr();
clock_t  start, end;
start=clock();
int bag,g,i,y,x,j,n=4;
cout<<"\n enter the size of BAG";
cin>>bag;
g=bag;
for (i=0;i<n;i++)
{
cout<<"\n Enter the item name ";
cin>>item[i].name;
cout<<"\n Enter the item price ";
cin>>item[i].price;
cout<<"\n Enter the item qty ";
cin>>item[i].qty;
item[i].avg=(float) item[i].qty/item[i].price;
}
for (i=0;i<n;i++)
	{ for (j=0;j<n-1;j++)
	  {
	  if (item[j].avg>item[j+1].avg)
	  {
		  temp=item[j];
		  item[j]=item[j+1];
		  item[j+1]=temp;
	    }
	    }
	    }

cout<<"\n name\t"<<"price\t"<<"qty\t"<<"avg\t";
 for (i=0;i<n;i++)
 { cout<<"\n\n"<<item[i].name<<"\t "<<item[i].price<<"\t "<<item[i].qty<<"\t "<<item[i].avg;
 }
 for (i=0;i<n;i++)
 {
 if (item[i].qty<=bag)
	{
       bag=abs(bag-item[i].qty);
      cout<<"\n\n bag conatin "<<item[i].name<<"\t quantity "<<item[i].qty;
      cout<<"\t\tcap"<<bag;
       }
       else
       {
       //bag=item[i].qty-bag;
       x=abs(item[i].qty-bag);
       if (bag>g)
       {
       bag=abs(bag-(item[i].qty-x));
       cout<<"\n bag conatin "<<item[i].name<<"\t quantity "<<item[i].qty;
       cout<<"\t\tcap"<<bag;
       break;
      }
      }
      if(bag==0)
      {
      cout<<"\n bag is full";
      break;
      }
    }
end= clock();

printf("\n total time %ld",(end-start)/CLK_TCK);

getch();
}
