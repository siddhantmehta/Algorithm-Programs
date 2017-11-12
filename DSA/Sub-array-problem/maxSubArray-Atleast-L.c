/*Find max. sub-array of length atleast 'l'. theta(n)*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a[15] = {10, 9, -7, 6, -5, -3, -4, 11, 20, 2, 0, -24, 31, -17, 23};
	int sum=0,i=0;
	int max=0;
	int  startLen =0, endLen=0;
	int length;
	printf("Enter the minimum length ");
	scanf("%d", &length);
	for (int k = 0; k < length; k++)
	{
		sum+=a[k];
	}
	max=sum;
	for (int m = 0; m < 15; m++) 
	{
		sum += a[m];
		if(sum>max&&m>=i+length)
		{
			startLen = i;
			max=sum;
			endLen =m;
		}
		if(sum<0)
		{
			i=m+1;
			sum=0;
		}
	}
	printf("Max sub array sum is %d from %d to %d\n", max, startLen+1, endLen+1);
}

