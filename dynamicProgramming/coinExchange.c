#include<stdio.h>
int main()
{
	int k;
	printf("Enter number of coins:");
	scanf("%d",&k);
	int coins[k];
	int i=0;
	for(i=0;i<k;i++)
	{
		scanf("%d",&coins[i]);
	}
	int amount;
	printf("Enter the amount to pay:");
	scanf("%d",&amount);
	int dpTable[amount+1][k];
	int j=0;
	i=0;
	while(i<amount+1)
	{
		dpTable[i][0]=i;
		i++;
	}
	j=0;
	while(j<k)
	{
		dpTable[0][j]=0;
		j++;
	}
	i=1;
	j=1;
	while(i<amount+1)
	{
		j=1;
		while(j<k)
		{
			dpTable[i][j]=dpTable[i][j-1];
			if(i>=coins[j] && dpTable[i][j]>dpTable[i-coins[j]][j])
			{
				dpTable[i][j]=1+dpTable[i-coins[j]][j];
			}
			j++;
		}
		i++;
	}
	for(i=0;i<amount+1;i++)
	{
		printf("%d | %d | %d \n",dpTable[i][0],dpTable[i][1],dpTable[i][2]);
	}
	printf("Number of coins to pay for %d is %d \n",amount,dpTable[amount][k-1] );

	i=11;
	j=k-1;
	int temp=0;
	while(i>0 || j>0)
	{
		if(dpTable[i][j]==dpTable[i][j-1])
		{
			j--;
		}
		else
		{
			printf("%d\n",coins[j]);
			i=i-coins[j];
		}
	}
	if(dpTable[i][j]!=0)
	{
		printf("%d\n",coins[j]);
	}
	//printf("value of i and j %d %d\n",i);
	return 0;
}