#include <stdio.h>
#include <conio.h>
int partition(int a[],int beg,int end){
    int loc,left,right,temp,index=0;
    loc=left=beg;
    right=end;
    int flag=0;
    while(flag!=1){
        while((a[loc]<a[right]) && (loc!=right))
        right--;
        if(loc==right)
        flag=1;
        else if(a[loc]>a[right])
        {
            temp=a[loc];
            a[loc]=a[right];
            a[right]=temp;
            loc=right;
        }
        if(flag!=1)
        {
            while((a[loc]>a[left])&&(loc!=left))
            left++;
            if(loc==left)
            flag=1;
            else if(a[loc]<a[left])
            {
                temp=a[loc];
                a[loc]=a[left];
                a[left]=temp;
                loc=left;
            }
        }
    }
   return loc; 
}
void quicksort(int a[],int beg,int end){
    int loc;
    if(beg<end){
        loc=partition(a,beg,end);
        quicksort(a,beg,loc-1);
        quicksort(a,loc+1,end);

    }
}
int main()
{
    int a[10],i,n;
    printf("\nEnter size ");
    scanf("%d",&n);
    printf("\nEnter %d elemenst ",n);

    for(i=0;i<n;i++)
    scanf("%d",&a[i]);

    quicksort(a,0,n-1);
    
    for(i=0;i<n;i++)
    printf("\n%d ",a[i]);
    return 0;
}
