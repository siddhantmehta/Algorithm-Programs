#include<stdio.h>
#include<malloc.h>
int main()
{
int count,n,k,i,j;
int *a;
scanf("%d %d",&n,&k);
if(n<2 && n>100) return;
if(k<1 && k<100) return;
a=(int *)malloc(n*sizeof(int));
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
for(i=0;i<n;i++)
{
if(a[i]<1 && a[i]>100) return;
}
count=0;
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if((i<j) && (a[i]+a[j])%k==0) count++;
}
}
printf("%d\n",count);
return 0;
}