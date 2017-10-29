#include<stdio.h>
int main()
{
int x=2;
int y=3;
x=x+y;
y=x-y;
x=x-y;
printf("%d------%d",x,y);
return 0;
}