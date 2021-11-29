#include<stdio.h>
#include<iostream.h>
#include<process.h>
#include<time.h>
 #include<conio.h>

#define MAX 10
#define TEMP 0
#define PERM 1
#define infinity 9999
struct node
{
	int predecessor;
	int dist;
	int status;
};
int adj[MAX][MAX];
int n;
void create_graph();
void display();
int findpath(int,int,int [],int *);
void main()
{   clrscr();
	int i,j;
	int source,dest;
	int path[MAX];
	int count,shortdist;
clock_t  start, end;
start=clock();

	create_graph();
	cout<<"The Adjacency Matrix is:-";
	display();
	while(1)
	{
		cout<<"Enter the source node(0 to quit) :";
		cin>>source;
		cout<<"Enter the destination node(0 to quit) :";
		cin>>dest;
		if (source==0||dest==0)
		exit(0);
		count=findpath(source,dest,path,&shortdist);
		if(shortdist!=0)
		{
			cout<<"Shortest distance is"<<shortdist;
			cout<<"Shortest path is:-";
			for(i=count;i>1;i--)
			cout<<path[i];
			cout<<endl;
		}
		else
		cout<<"There are no poath from source to destination";
	}
end= clock();
printf("\n total time %ld",(end-start)/CLK_TCK);

}
void create_graph()
{
	int i,max_edge,origin,destin,wt;
	cout<<"Enter the node";
	cin>>n;
	max_edge=n*(n-1);
	for(i=1;i<max_edge;i++)
	{
		cout<<"enetr edge (0 0 to quit) "<<i;
		cin>>origin>>destin;
		if((origin==0)&&(destin==0))
		break;
		cout<<"enter weight for this edge";
		cin>>wt;
		if(origin>n||destin>n||origin<=0||destin<=0)
		{
			cout<<"Invalid edge";
			i--;
		}
		else
		adj[origin][destin]=wt;
	}
}
void display()
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		cout<<"\t"<<adj[i][j];
		cout<<endl;
	}
}
int findpath(int s,int d,int path[MAX],int *sdist)
{
	struct node state[MAX];
	int i,min,count=0,current,newdist,u,v;
	*sdist=0;
	for(i=1;i<=n;i++)
	{
		state[i].predecessor=0;
		state[i].dist=infinity;
		state[i].status=TEMP;
	}
	state[1].predecessor=0;
	state[1].dist=0;
	state[1].status=PERM;
	current=s;
	while(current!=d)
	{
		for(i=1;i<=n;i++)
		{
			if(adj[current][i]>0 && state[i].status==TEMP)
			{
				newdist=state[current].dist+adj[current][i];
				if(newdist<state[i].dist)
				{
					state[i].predecessor=current;
					state[i].dist=newdist;
				}
			}
		}
		min=infinity;
		current=0;
		for(i=1;i<=n;i++)
		{
			if(state[i].status==TEMP && state[i].dist<min)
			{
				min=state[i].dist;
				current=i;
			}
	   }
	   if(current==0)
	   return 0;
	   state[current].status=PERM;
	}
	while(current!=0)
	{
		count++;
		path[count]=current;
		current=state[current].predecessor;
	}
	for(i=count;i>1;i--)
	{
		u=path[i];
		v=path[i-1];
		*sdist+=adj[u][v];
	}
	return count;
}
