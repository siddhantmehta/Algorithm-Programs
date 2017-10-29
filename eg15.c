#include<stdio.h>
int main()
{
int a[5]={1,2,3,4,5};
int i,j,max,temp;
for(i=4;i>=0;i--)
{
max=i;
for(j=i-1;j>=0;j--)
{
if(a[j]<a[max]) max=j;
}
temp=a[i];
a[i]=a[max];
a[max]=temp;
}
for(i=0;i<5;i++) printf("%d\n",a[i]);
return 0;
}