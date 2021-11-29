#include<iostream.h>
#include<conio.h>
#include<time.h>
#include<stdio.h>
void main()
{
clrscr();
	int a[8][8],b[8],i,j,k,r,c,r1,c1,flag=1;
clock_t  start, end;
start=clock();

	clrscr();

for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		a[i][j]=1;
	}
	aa:
	for(i=0;i<8;i++)
	{
		cout<<"enter the position of column of "<<i<<" row";
		cin>>b[i];
		if (b[i]>=8)
		 {
			cout<<"wrong choice";
			goto aa;
		 }
	}
	k=0;
	while(k<8)
	{
		r=k;
		c=b[k];
		if(a[r][c]==1)
		flag=1;
		else
		{
			flag=0;
			break;
		}
		for(i=0;i<8;i++)
		{
			a[r][i]=0;
			a[i][c]=0;
		}
		r1=r; c1=c;
		for(i=0;i<8;i++)
		{
			a[r1--][c1--]=0;
			if(r1==-1||c1==-1)
				break;
		}
		r1=r;c1=c;
		for(i=0;i<8;i++)
		{
			a[r1++][c1++]=0;
			if(r1==8||c1==8)
				break;
		}
		r1=r;c1=c;
		for(i=0;i<8;i++)
		{
			a[r1++][c1--]=0;
			if(r1==8||c1==-1)
				break;
		}
		r1=r;c1=c;
		for(i=0;i<8;i++)
		{
			a[r1--][c1++]=0;
			if(r1==-1||c1==8)
				break;
		}
		k++;
	}
	if(flag==1)
	cout<<"right solution well done";
	else
	cout<<"wrong solution  wann try more";
	cout<<endl;
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		cout<<a[i][j]<<"\t";
		cout<<"\n";
	}
end= clock();
printf("\n total time %ld",(end-start)/CLK_TCK);
getch();
}
