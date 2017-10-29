#include<stdio.h>
int main()
{
int s,n,m;
n=5;
m=910271928;
s=5;
int t=m%n;
printf("%d\n",t);
if(t+s-1 == 0) printf("%d\n",n);
else printf("%d\n",t+s-1);
return 0;
}