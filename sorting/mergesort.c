#include<stdio.h>
void merge(int *x, int low, int high, int mid)
{
int c[50],i,j,k;
i=low;
j=mid+1;
k=low;
while(i<=mid && j<=high)
{
if(x[i]<x[j])
{
c[k]=x[i];
i++;
k++;
}
else
{
c[k]=x[j];
j++;
k++;
}
}
while(i<=mid)
{
c[k]=x[i];
i++;
k++;
}
while(j<=high)
{
c[k]=x[j];
j++;
k++;
}
i=0;
while(i<k)
{
x[i]=c[i];
i++;
}
}
void mergesort(int *x, int low, int high)
{
int mid;
if(low<high)
{
mid=(low+high)/2;
mergesort(x,low,mid);
mergesort(x,mid+1,high);
merge(x,low,high,mid);
}
}
int main()
{
int x[10],y;
y=0;
while(y<10)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
y++;
}
mergesort(x,0,9);
y=0;
while(y<10)
{
printf("%d\n",x[y]);
y++;
}
return 0;
}