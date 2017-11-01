//Largest Sum Contiguous Subarray - Kadane's Algorithm
#include<stdio.h>
int main()
{
	int arr[]={-2,-3,4,-1,-2,1,5,-3};
	int size=sizeof(arr)/sizeof(arr[0]);
	int i,a,b,s,maxSum,sum;
	s=0;
	i=0;
	sum=0;
	maxSum=0;
	while(i<size)
	{
		sum=sum+arr[i];
		if(sum>maxSum)
		{
			maxSum=sum;
			a=s;
			b=i;
		}
		if(sum<0)
		{
			sum=0;
			s=i+1;
		}
		i++;
	}
	printf("Maximum sum:%d\n",maxSum);
	return 0;
}
