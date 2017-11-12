/*to find if a mojority number exists in the array. Number is majority if it is present (n/3)+1 times. theta(n). bucket analogy. If n/k is majority then check if there are k-1 terms in the bucket.*/

#include <stdio.h>

int main()
{
	int c1=0, c2=0, i, flag=0, count=0;
	int a[10] = {2,1,2,1,1,3,3,4,5};
	//int a[10] = {2,2,1,4,10,5,8,11,9,0};
	int n = 10;
	int first = 0;
	int last = 9;
	int A=0, B=0;

	for (i=0; i<n; i++)
	{
		if (c1>0 && A==a[i])
			c1++;
		else if (c2>0 && B==a[i])
			c2++;
		else if (c1==0)
		{
			c1 = 1;
			A=a[i];	
		}
		else if (c2 == 0)
		{
			c2=1;
			B=a[i];
		}
		else 
		{
			c1--;
			c2--;
		}
		//printf("c1=%d\n", c1);
		//printf("c2=%d\n", c2);
	}
	if ((c1>2) || (c2>2))
		printf("Present\n");
	else
		printf("Not present\n");
	return 0;	
}
