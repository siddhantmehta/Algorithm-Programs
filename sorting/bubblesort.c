#include<stdio.h>
void bubblesort(int *x,int size)
{
int m,e,f,g;
m=size-2;
while(m>=0)
{
e=0;
f=e+1;
while(e<=m)
{
if(x[e]>x[f])
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
e++;
f++;
}
m--;
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
bubblesort(x,10);
y=0;
while(y<10)
{
printf("%d\n",x[y]);
y++;
}
return 0;
}