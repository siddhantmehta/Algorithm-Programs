/* Insert, Delete, replace to convert one string to other.

  dp[i][j-1],  // Insert
  dp[i-1][j],  // Remove
  dp[i-1][j-1]); // Replace
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min2(int a, int b)
{
	if(a>=b)
		return b;
	else
		return a;
}

int min(int a, int b, int c)
{
	return min2(min2(a, b), c);
}

int editDistance(char str1[], char str2[], int str1len,  int str2len)
{
	int cost[str1len+1][str2len+1];
	
	for (int i=0; i<=str1len; i++)
	{
		for (int j=0; j<=str2len; j++)
		{
			if (i==0)
				cost[i][j] = j; //first string is empty. add second string char to first.
			else if(j==0)
				cost[i][j] = i; //second string is empty. add first char to second.
			else if(str1[i-1] == str2[j-1])
				cost[i][j] = cost[i-1][j-1];
			else
				cost[i][j] = 1 + min(cost[i][j-1], cost[i-1][j], cost[i-1][j-1]); 
		}
	}
	return cost[str1len][str2len];
}

int main()
{
	char str1[] = "Sunday";
	char str2[] = "Saturday";

	printf("Number of operation required to change from string1 to string2 are %d\n", editDistance(str1, str2, strlen(str1), strlen(str2)));
	return 0;
}
