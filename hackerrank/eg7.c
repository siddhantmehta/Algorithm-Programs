#include<stdio.h>
int main()
{
int n,i,j,k;
scanf("%d",&n);
for(i=n;i>0;i--)
{
for(j=0;j<i-1;j++)
{
printf(" ");
}
for(k=0;k<=n-i;k++)
{
printf("#");
}
printf("\n");
}
return 0;
}