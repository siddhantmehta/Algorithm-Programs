/*Print all the minimum from sub-array length 'k'. theta(n)*/

#include <stdio.h>

int min(int x, int y)
{
	if(x<=y)
		return x;
	else 
		return y;
}

int main()
{
	int a[8] = {3, 9, 12, 6, 14, 5, 1, 23};
	int leftArr[8], rightArr[8];
	int n = 8;	//array size
	int w = 4;	//window size
	int k = n-w+1;	//no. of windows
	int i;	
	
	for(i = 0; i < n; i++)		//from left to right find min
	{ 
        	if(i % w == 1) 
            		leftArr[i] = a[i];
        	else
            		leftArr[i] = min(leftArr[i - 1], a[i]);        
    	}

	for(i = n; i >= 1; i--)		//from right to left find min
	{ 
        	if(i == n)  
            		rightArr[i] = a[i]; 
        	else if(i % w == 0) 
            		rightArr[i] = a[i];
        	else
            		rightArr[i] = min(rightArr[i+1], a[i]);
    	}

	printf("The min. values are ");

	for(i = 1; i <= k; i++)    // maximum
        	printf("%d\t", min(rightArr[i], leftArr[i + w - 1]));

	printf("\n");
}
