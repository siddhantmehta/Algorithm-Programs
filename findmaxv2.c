//find max(a[j]-a[i] where j>i+l)
#include<stdio.h>
int findmax(int *a,int n,int l)
{
int i=0;
int j=l;
int max=a[j]-a[i];
j++;
while(j<n)
{
if(a[i]>a[j-l]) i=j-l;
if(a[j]-a[i]>max) max=a[j]-a[i];
j++;
}
return max;
}
int main()
{
int n;
scanf("%d",&n);
int l;
scanf("%d",&l);
int a[n],i;
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
int max = findmax(a,n,l);
printf("%d\n",max);
return 0;
}