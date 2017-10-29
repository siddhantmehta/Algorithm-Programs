#include<stdio.h>
int partition(int *a,int p, int r)
{
int x,i,j,t;
x=a[r];
i=p-1;
for(j=p;j<r;j++)
{
if(a[j]<=x)
{
i++;
t=a[i];
a[i]=a[j];
a[j]=t;
}
}
t=a[i+1];
a[i+1]=a[r];
a[r]=t;
return i+1;
}
void quicksort(int *a, int low,int high)
{
if(low<high)
{
int k=partition(a,low,high);
quicksort(a,low,k-1);
quicksort(a,k+1,high);
}
}
int main()
{
int a[10],i;
for(i=0;i<10;i++)
{
scanf("%d",&a[i]);
}
quicksort(a,0,9);
for(i=0;i<10;i++)
{
printf("%d\n",a[i]);
}
return 0;
}