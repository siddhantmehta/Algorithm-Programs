//Knapscak problem

#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
	if(a>=b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int knapSack(int W, int weight[], int value[], int n)
{
	int k[n+1][W+1];
	for (int i=0; i<=n; i++)
	{
		for (int j=0; j<=W; j++)
		{
			if(i==0 || j==0)
				k[i][j] = 0;
			else if(weight[i-1]<=W)
				k[i][j] = max(value[i-1] + k[i-1][j-weight[i-1]], k[i-1][j]);
			else
				k[i][j] = k[i-1][j];
				
		}
	}
	return k[n][W];
}

int main()
{
    	int value[] = {60, 100, 120};
    	int weight[] = {10, 20, 30};
    	int  W = 50;
    	int n = sizeof(value)/sizeof(value[0]);
    	printf("%d\n", knapSack(W, weight, value, n));
    	return 0;
}
