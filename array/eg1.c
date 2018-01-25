//Program for array rotation
#include<stdio.h>
#include<malloc.h>
int main()
{
	int n;
	scanf("%d",&n);
	int *a,*b;
	a=(int *)malloc(sizeof(int)*n);
	b=(int *)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int d;
	scanf("%d",&d);
	d=d%n;
	int k,j;
	k=0;
	j=d;
	while(j<n)
	{
		b[k]=a[j];
		k++;
		j++;
	}
	j=d-1;
	while(j>=0)
	{
		b[k]=a[j];
		j--;
		k++;
	}
	for(int i=0;i<n;i++)
	{
		printf("%d ",b[i]);
	}
	return 0;
}