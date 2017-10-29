#include<stdio.h>
void selectionsort(int *x, int size)
{
int e,f,g,m;
e=0;
while(e<=size-2)
{
f=e+1;
m=e;
while(f<=size-1)
{
if(x[m]>x[f])
{
m=f;
}
f++;
}
g=x[e];
x[e]=x[m];
x[m]=g;
e++;
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
selectionsort(x,10);
y=0;
while(y<10)
{
printf("%d\n",x[y]);
y++;
}
return 0;
}