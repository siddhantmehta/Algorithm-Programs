#include<stdio.h>
int main()
{
	int n;
	printf("Enter the number of elements:");
	scanf("%d",&n);
	int s[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&s[i]);
	}
	int sum;
	printf("Enter the sum:");
	scanf("%d",&sum);
	int dpTable[n][sum+1];
	for(int i=0;i<sum+1;i++)
	{
		if(i==s[0])
		{
			dpTable[0][i]=1;
		}
		else 
		{
			dpTable[0][i]=0;
		}
	}
	for(int i=0;i<n;i++)
	{
		dpTable[i][0]=1;
	}
	int i=1;
	int j=1;
	while(j<sum+1)
	{
		i=1;
		while(i<n)
		{
			dpTable[i][j]=dpTable[i-1][j];
			if(j>=s[i] && dpTable[i-1][j-s[i]]!=0)	
			{
				dpTable[i][j]=dpTable[i-1][j-s[i]];
			}
			i++;
		}
		j++;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<sum+1;j++)
		{
			if(dpTable[i][j]==1)
			printf("T ");
		else
			printf("F ");
		}
		printf("\n");
	}
	i=n-1;
	j=7;
	while(i>0 && j>0)
	{
		if(dpTable[i][j]==dpTable[i-1][j])
		{
			i--;
		}
		else
		{
			printf("%d\n",s[i]);
			j=j-s[i];
			i--;
		}
	}
	return 0;
}