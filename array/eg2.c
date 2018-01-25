//Program for array rotation(Using reversal Algorithm)
#include<stdio.h>
#include<malloc.h>
void reverse(int *a,int start,int end)
{
	int i,j,g;
	i=start;
	j=end;
	while(i<j)
	{
		g=a[i];
		a[i]=a[j];
		a[j]=g;
		i++;
		j--;
	}
}
void rotate(int *a,int n,int d)
{
	reverse(a,0,d-1);
	reverse(a,d,n-1);
	reverse(a,0,n-1);
}
int main()
{
	int n;
	scanf("%d",&n);
	int *a;
	a=(int *)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int d;
	scanf("%d",&d);
	rotate(a,n,d);
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}