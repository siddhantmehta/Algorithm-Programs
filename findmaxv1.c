//find max(a[j]-a[i] where j>i)
#include<stdio.h>
int findmax(int *a,int n)
{
int i=0;
int j=1;
int max=a[j]-a[i];
j++;
while(j<n)
{
if(a[i]>a[j-1]) i=j-1;
if(a[j]-a[i]>max) max=a[j]-a[i];
j++;
}
return max;
}
int main()
{
int n;
scanf("%d",&n);
int a[n],i;
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
int max = findmax(a,n);
printf("%d\n",max);
return 0;
}