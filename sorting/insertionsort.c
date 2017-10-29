#include<stdio.h>
void insertionsort(int *x, int lb, int ub)
{
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
insertionsort(x,0,9);
y=0;
while(y<10)
{
printf("%d\n",&x[y]);
y++;
}
return 0;
}