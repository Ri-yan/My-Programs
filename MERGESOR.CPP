#include<iostream.h>
#include<conio.h>
#define size 100
void merge(int a[size],int beg,int mid,int end){
int i=beg, j=mid+1,index=beg,temp[size],k;
  while(i<=mid && j<=end){
  if(a[i]<a[j])
  {temp[index]=a[i];
   i++;
  }
  else{
  temp[index]=a[j];
  j++;
  }
  index++;
  }
  if(i>mid){
  while(j<=end)
  temp[index++]=a[j++];
  }
  else{
  while(i<=mid)
  temp[index++]=a[i++];
  }
  for(k=beg;k<index;k++)
  a[k]=temp[k];
}
void mergesort(int a[size],int beg,int end){
 int mid;
 if(beg<end){
 mid=(beg+end)/2;
 mergesort(a,beg,mid);
 mergesort(a,mid+1,end);
 merge(a,beg,mid,end);
 }
}
void main(){
clrscr();
int a[size],i,n;
cout<<"Enter Size\n";
cin>>n;
cout<<"Enter "<<n<<" array element\n";
for(i=0;i<n;i++)
cin>>a[i];
mergesort(a,0,n-1);
cout<<"\nSorted Array is\n";
for(i=0;i<n;i++)
cout<<a[i]<<"\t";
getch();
}