//Matrix chain Multiplication order.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int matOrdMult(int arr[], int n)
{
	int m[n][n];
	int j, cost;
	
	for(int i=1; i<n; i++)
	{
		m[i][i] = 0;
	}

	for(int l=2; l<n; l++)
	{
		for (int i=1; i<n-l+1; i++)
		{
			j = i+l-1;
            		m[i][j] = INT_MAX;
            		for (int k=i; k<=j-1; k++)
            		{
                		cost = m[i][k] + m[k+1][j] + arr[i-1]*arr[k]*arr[j];
                		if (cost < m[i][j])
                   	 	m[i][j] = cost;
            		}
		}
	}
}

int main()
{
	int arr[] = {1, 2, 3, 4};
	int n = sizeof(arr)/ sizeof(arr[0]);
	printf("The minimum number of multiplication required for given order of matrices is %d\n", matOrdMult(arr, n));
	return 0; 
}
