#include<stdio.h>
int sum(int *a,int n)
{
int i=0;
while(i<n)
{
printf("%d\n",a[i]);
i++;
}
}
int main()
{
int a[5]={1,2,3,4,5};
sum(a+1,5);
return 0;
}