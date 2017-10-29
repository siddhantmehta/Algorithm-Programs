#include<stdio.h>
int main()
{
	int n;
	printf("Enter the number of items:");
	scanf("%d",&n);
	int weights[n],values[n];
	for(int i=0;i<n;i++)
	{
		printf("Enter weight:");
		scanf("%d",&weights[i]);
		printf("Enter value:");
		scanf("%d",&values[i]);
	}
	int profit;
	printf("Enter profit:");
	scanf("%d",&profit);
	int dpTable[n][profit+1];
	for(int j=0;j<profit+1;j++)
	{
		if(j<=values[0])
		{
			dpTable[0][j]=weights[0];
		}
		else
			dpTable[0][j]=98765;
	}
	for (int i = 0; i < n; ++i)
	{
		dpTable[i][0]=98765;
	}
	int i=1;
	int j=1;
	while(j<profit+1)
	{
		i=1;
		while(i<n)
		{
			dpTable[i][j]=dpTable[i-1][j];
			if(j>=values[i] && dpTable[i][j]<weights[i]+dpTable[i-1][j-values[i]])
			{
				dpTable[i][j]=weights[i]+dpTable[i-1][j-values[i]];
			}
			i++;
		}
		j++;
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < profit+1; ++j)
		{
			printf("%d ",dpTable[i][j]);
		}
		printf("\n");
	}
	printf("Maximum weight :%d\n",dpTable[n-1][profit]);
	i=n-1;
	j=profit;
	while(i>0 || j>0)
	{
		if(i!=0 && dpTable[i][j]==dpTable[i-1][j])
		{
			i--;
		}
		else
		{
			printf("%d %d\n",weights[i],values[i]);
			j=j-values[i];
			i--;
		}
	}
	return 0;
}