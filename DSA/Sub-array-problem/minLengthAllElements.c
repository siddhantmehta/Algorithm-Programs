/*Find the min. sub-array which has all the elements from 1to k.*/

#include<stdio.h>

int main()
{
	//int a[16] = {1, 2, 10, 6, 3, 1, 2, 7, 6, 4, 2, 8, 6, 1, 7, 3};
	int a[16] = {1, 2, 3, 5, 4, 1, 2, 7, 6, 4, 2, 8, 1, 2, 3, 4};
	int n = 16, first = 0, i, k, C[100] = {0}, count=0, j, minlength = n-first, length, newfirst=0, l, m;

	k=4;

	for (i=0; i<n; i++)
	{
		if (a[i] <= k)
		{
			C[a[i]]++;
			if (C[a[i]] == 1)
			{
				count++;
			}
		}


		length = i-newfirst+1;
		j = newfirst;
		while (count == k)
		{
			if (a[j] > k)
			{
				length--;
			}
			else 
			{
				if((count == k))
				{
					//printf("length=%d\n", length);
					if (length < minlength)
						minlength = length;
					newfirst = j;
					count = 0;
				}
				else
				{
					length--;
					C[a[j]]--;
				}
			}				
			j++;
		}
	}
	//minlength = n-first+1;
	printf("The min. sub-array length is %d\n", minlength);
}
