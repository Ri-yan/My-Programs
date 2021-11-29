#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include<process.h>
#include<time.h>

#define MAX 10
#define TEMP 0
#define PREM 1
#define infinity 9999
#define FALSE 0
#define TRUE 1
struct node
{
	int predecessor;
	int dist;
	int status;
};
struct edge
{
int u,v;
};
struct node state[MAX];
void create_graph();
void display();
int adj[MAX][MAX];
int n;
int maketree(struct edge[], int *);
int all_perm (struct node []);

void main()
{
int i,j;
clrscr();
struct edge tree[MAX];
int path [MAX];
int count, wt_tree;
clock_t  start, end;
start=clock();

create_graph();
cout<<"\n Adjectent Matrix is\n";
display();
count =maketree(tree, &wt_tree);
cout <<"\n Weight of spanning tree is "<< wt_tree;
cout<<"\n edge tobe included in the tree ";
for (i=1;i<=count;i++)
{
cout<<tree[i].u<<"->";
cout<<tree[i].v<<"\t";
}
end= clock();
printf("\n total time %ld",(end-start)/CLK_TCK);

getch();
}
void create_graph()
{
	int i,max_edge,origin,destin,wt;
	cout<<"Enter the node ";
	cin>>n;
	max_edge=n*(n-1);
	for(i=1;i<max_edge;i++)
	{
		cout<<"enetr edge (0 0 to quit) "<<i;
		cin>>origin>>destin;
		if((origin==0)&&(destin==0))
		break;
		cout<<"enter weight for this edge ";
		cin>>wt;
		if(origin>n||destin>n||origin<=0||destin<=0)
		{
			cout<<"Invalid edge";
			i--;
		}
		else
	     {	adj[origin][destin]=wt;
		adj[destin][origin]=wt;
	      }

}
if (i<n-1)
{
cout<<"\n Spanning tree is not Possible ";
exit(1);
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


int maketree (struct edge tree[MAX], int *weight)
{
int i,k, min, count, current,newdist,m, u1,v1;
*weight =0;

	for (i=1;i<=n; i++)
	{
	state[i].predecessor=0;
	state[i].dist=infinity;
	state[i].status=TEMP;
	}// for
	state[i].predecessor=0;
	state[i].dist=0;
	state[i].status=PREM;
	current=1;
	count=0;
while (all_perm(state)!=TRUE)
{
	for (i=1;i<=n;i++)
		{
		if (adj[current][i]>0&& state[i].status==TEMP)
			{
			if (adj[current][i]<state[i].dist)
				{
				state[i].predecessor=current;
				state[i].dist=adj[current][i];
				}//if
			}//if
		}// for
	min=infinity;
	for (i=1;i<=n;i++)
		{
		   if (state[i].status==TEMP&& state[i].dist<min)
			{
			min =state[i].dist;
			current=i;
			}// if
		} //for
	state[current].status=PREM;
	u1=state[current].predecessor;
	v1=current;
	count++;
	tree[count].u=u1;
	tree[count].v=v1;
	*weight+=adj[u1][v1];
	}// while
	return count;

	   }//fun

	int all_perm( struct node[MAX])
		{
		int i;
		for (i= 1;i<=n;i++)
		if (state[i].status==TEMP)
	return FALSE;
	return TRUE;
	}// fun
