#include<stdio.h>
#include<malloc.h>
int main()
{
int n,d,i,j,g,t;
int *a,*b;
scanf("%d %d",&n,&d);
if(n<1 && n>100000) return;
if(d<1 && d>n) return;
a=(int *)malloc(n*sizeof(int));
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
t=d%n;
b=(int *)malloc(n*sizeof(int));
j=0;
for(i=t;i<n;i++)
{
b[j]=a[i];
j++;
}
for(i=0;i<t;i++)
{
b[j]=a[i];
j++;
}
for(i=0;i<n;i++)
{
printf("%d ",b[i]);
}
return 0;
}