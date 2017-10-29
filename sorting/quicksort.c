#include<stdio.h>
int findPartitionPoint(int *x, int lb, int ub)
{
int e,f,num,g;
e=lb;
f=ub;
num=x[lb];
while(1)
{
while(1)
{
if(e==ub || x[e]>num)
{
break;
}
e++;
}
while(1)
{
if(f==lb || x[f]<num)
{
break;
}
f--;
}
if(e<f)
{
/*x[e]=x[e]+x[f];
x[f]=x[e]-x[f];
x[e]=x[e]-x[f];*/
g=x[e];
x[e]=x[f];
x[f]=g;
}
else
{
/*x[lb]=x[lb]+x[f];
x[f]=x[lb]-x[f];
x[lb]=x[lb]-x[f];*/
g=x[lb];
x[lb]=x[f];
x[f]=g;
break;
}
}
return f;
}
void quicksort(int *x, int lb, int ub)
{
if(ub<=lb) return;
int partitionPoint;
partitionPoint=findPartitionPoint(x,lb,ub);
quicksort(x,lb,partitionPoint-1);
quicksort(x,partitionPoint+1,ub);
}
int main()
{
int x[10],y;
y=0;
while(y<10)
{
printf("Enter the number : ");
scanf("%d",&x[y]);
y++;
}
quicksort(x,0,9);
y=0;
while(y<10)
{
printf("%d\n",x[y]);
y++;
}
return 0;
}