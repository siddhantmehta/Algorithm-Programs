#include<stdio.h>
#include<malloc.h>
int convertToBinary(int n,int *m)
{
int y,i;
y=n;
i=0;
while(y!=0)
{
m[i]=y%2;
y=y/2;
i++;
}
return i;
}
int main()
{
int i,oldCount,newCount,n,j,y,t;
int *x;
scanf("%d",&n);
if(n<1 && n>1000000) return;
x=(int *)malloc(32*sizeof(int));
i=convertToBinary(n,x);
oldCount=0;
newCount=0;
for(j=0;j<i;j++)
{
if(x[j]==1)
{
newCount++;
if(newCount<oldCount)
{
t=1;
}
else t=0;
}
else
{
if(newCount>oldCount) oldCount=newCount;
newCount=0;
}
}
if(t==1) printf("%d\n",oldCount);
else printf("%d\n",newCount);
return 0;
}