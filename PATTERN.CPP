#include<iostream.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<time.h>

void main()
{
	char text[25],pattern[25];
	int posi,len1,len2,tlen2,k=0,p=0,i=0,j=0,l=0,flag=0;
	clrscr();
clock_t  start, end;
start=clock();

	cout<<"Enter the text:-";
	gets(text);
	cout<<"Enter the pattern for matching";
	gets(pattern);
	len1=strlen(text);
	len2=strlen(pattern);
	tlen2=len2;

	while(text[k]!=NULL)
	{
		k++;
		//while(tlen2)
//			{
			p++;
			    if (text[i]==pattern[j])
				{
				l++,i++,j++;
				tlen2--;
					if(l==len2)
					{
					cout<<"\n Patter found";
					cout<< "\n at Postion "<<p-len2;
					flag=1;
					} // if
				}// if

		else
		{
		i++,j=0,l=0,tlen2=len2;
		}
	}// while
  //	}       // while

	if (flag==0)
	cout<<"\n Not Found";
end= clock();
printf("\n total time %ld",(end-start)/CLK_TCK);
getch();
}
