//To find whether sum is present in the array

#include <stdio.h>
#include <stdlib.h>

int subsetSum(int arr[], int n, int sum)
{
	int table[sum+1][n+1];

	for (int i = 0; i <= n; i++)
      		table[0][i] = 1;

	for (int i = 1; i <= sum; i++)
      		table[i][0] = 0;

	for (int i=1; i<=sum; i++)
	{
		for (int j=1; j<=n; j++)
		{
			table[i][j] = table[i][j-1];
			if (i >= arr[j-1])
			{
				table[i][j] = table[i][j] || table[i - arr[j-1]][j-1];
			}
		}
	}
	return table[sum][n];
}

int main()
{
	int arr[] = {3, 34, 4, 12, 5, 2};
	int sum;
	printf("Enter the sum to find: ");
	scanf("%d", &sum);
	int n = sizeof(arr)/ sizeof(arr[0]);
	if (subsetSum(arr, n, sum) == 1)
		printf("The sum is present\n");
	else
		printf("The sum is not present\n");
	return 0;
}
