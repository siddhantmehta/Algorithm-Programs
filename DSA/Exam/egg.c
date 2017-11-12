#include <stdio.h>
#include <stdio.h>
#include <limits.h>

int trial(int n, int k);
int max(int x, int y);

int main()
{
	int n, k, floorNo=0; 
	printf("Enter the number of floors: ");
	scanf("%d", &n);
	printf("Enter the number of eggs: ");
	scanf("%d", &k);
	int trialno = trial(n , k);
	printf("The minimum no. of trials required are: %d\n", trialno);

	for(int i=n;;i--)
        {
            if(trial(i,k-1) == trialno)
            {
                floorNo = floorNo + i + 1;
                if(floorNo >= n)
                {
                    printf("The floor is %d\n", n);
                    break;
                }
                printf("The floor is %d\n", floorNo);
                trialno--;
            }
        }

	return 0;
}

int trial(int n, int k)
{
	int minTrialArr[n+1][k+1];
	int min;
	
	for (int i = 1; i <= k; i++)
	{
		minTrialArr[1][i] = 1;	//one trial required for 1 floor
		minTrialArr[0][i] = 0;	//zero trial required for 0 floor
	}
	
	for(int i = 0; i <= n; i++)
	{
		minTrialArr[i][1] = i;	//i trial for 1 egg and n floors.
	}

	for(int i = 2; i <= k; i++)
	{
		for(int j = 2; j <=n ; j++)
		{
			minTrialArr[j][i] = INT_MAX;
			for(int k = 1; k <=j; k++)
			{
				min = 1 + max(minTrialArr[k-1][i-1], minTrialArr[j-k][i]); 
				if(min < minTrialArr[j][i])
				{
					minTrialArr[j][i] = min;
				}
			}
		}
	}

	return minTrialArr[n][k];
	
	
}

int max(int x, int y)
{
	if(x >= y)
		return x;
	else
		return y;
}
