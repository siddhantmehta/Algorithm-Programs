/*Find max. sub-array of length atmost 'l'. theta(n)*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a[15] = {10, 9, -7, 6, -5, -3, -4, 11, 20, 2, 0, -24, 31, -17, 23};
	int sum=0,i=0;
	int max;
	int  startLen =0, endLen=0;
	int length;
	printf("Enter the maximum length ");
	scanf("%d", &length);
	max=sum;
	for (int k = 0; k < 15; k++) 
	{
		sum += a[k];
		if(sum>max)
		{
			startLen = i;
			max=sum;
			endLen = k;
		}
		if(sum<0)
		{
			i=k+1;
			sum=0;
		}
		if(k-i==length)
		{
			sum-=a[i];
			i++;
		}
	}
	printf("Max sub array sum is %d from %d to %d\n", max, startLen+1, endLen+1);
}
