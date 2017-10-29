#include<stdio.h>
void linearsort(int *x,int size)
{
int e,f,g;
e=0;
while(e<=size-2)
{
f=e+1;
while(f<=size-1)
{
if(x[e]>x[f])
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
f++;
}
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
linearsort(x,10);
y=0;
while(y<10)
{
printf("%d\n",x[y]);
y++;
}
return 0;
}