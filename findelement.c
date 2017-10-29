//find the element if its rank is given
//Rank(x) is one plus the no. of elements greater than x
#include<stdio.h>
#include<stdlib.h>
int rPivot(int *a,int i,int j)
{
return i+rand()%(j-i+1);
}
int partition(int *a,int i,int j,int p)
{
int l,r,t;
l=i;
r=j;
while(l<r)
{
while(l<r && a[l]<a[p]) l++;
while(l<r && a[r]>a[p]) r--;
if(l<r)
{
t=a[l];
a[l]=a[r];
a[r]=t;
l++;
r--;
}
else
{
t=a[l];
a[l]=a[p];
a[p]=t;
}
}
return l-1;
}
int findElement(int *a,int i,int j,int r)
{
if(j<i) return -1;
int p,k;
p=rPivot(a,i,j);
printf("Random %d\n",p);
k=partition(a,i,j,p);
//printf("%d\n",k);
if(r==j-k+1) return k;
else if(r<j-k+1) findElement(a,k+1,j,r);
else
findElement(a,i,k-1,r-(j-k+1));
}
int main()
{
int n;
scanf("%d",&n);
int a[n],i,r,x;
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
scanf("%d",&r);
x=findElement(a,0,n-1,r);
if(x==-1) printf("Not found\n");
else printf("Element %d",x);
return 0;
}