
#include<stdio.h>
int partition(int x[],int left,int right)
{
int p=x[right];
int lhs=left;
int rhs=right-1;
int g;
while(lhs<=rhs)
{
while(lhs<=rhs && x[lhs]<=p)
{
lhs=lhs+1;
}
while(lhs<=rhs && x[rhs]>=p)
{
rhs=rhs+1;
}
if(lhs<rhs)
{
g=x[lhs];
x[lhs]=x[rhs];
x[rhs]=g;
}
else
{
g=x[lhs];
x[lhs]=x[right];
x[right]=g;
break;
}
}
return lhs;
}
void quickSort(int a[],int left,int right)
{
if(left>=right) return;
int pivot=partition(a,left,right);
quickSort(a,left,pivot-1);
quickSort(a,pivot+1,right);
}
int main()
{
int x[12],y;
y=0;
while(y<=11)
{
printf("Enter a number:");
scanf("%d",&x[y]);
y++;
}
quickSort(x,0,11);
y=0;
while(y<=11)
{
printf("%d\n",x[y]);
y++;
}
return 0;
}