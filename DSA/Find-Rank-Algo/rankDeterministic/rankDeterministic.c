#include<stdio.h>


	void swap(int a[], int l, int r);
	int findRank(int a[], int i, int j, int r);
	//SELECTION SORT 
	void sort(int A[],int l,int r)
	{
 		int min,x;
		
		for(int i=l;i<=r;i++)
 		{
  			min =i;  //index of minimum element
  			for(int j=i+1;j<=r;j++)
  			{
   				if(A[min]>=A[j])
   				{
   					min=j;
   				}	
  			}
  			swap(A, min, i);

 		}

	}
	void swap(int a[], int l, int r)
	{
		int temp =a[l];
		a[l] = a[r];
		a[r] = temp;
	}

	int goodPivot(int a[], int l, int r)
	{
		// Sorting in groups of 5

		int beg = l;
		int end = r;
		int rem = (r-l+1)%5;
		int groups;
		if(rem == 0)
			groups = (r-l+1) / 5;
		else 
			groups = ((r-l+1) / 5) + 1;

		for(int i = 0; i < groups; i++, beg += 5)
		{
			if( i == (groups - 1))
			{
				if(rem == 0)
					sort(a, beg, beg+4);
				else
				{
					sort(a, beg, beg+rem-1);
				}
					
			}
			else
			{
				sort(a, beg, beg+4);
			}
		}

		if((r-l+1) <= 5)
			return ((l+r)/2);

		// Median movement
		beg = l;
		end = r;
		int start =l;
		for(int i=0; i< groups; i++, beg += 5)
		{
			if(i == (groups - 1))
			{
				if(rem == 0)
					swap(a, start++, beg+2);
				else
					swap(a, start++, beg + (rem/2));
			}
			else
				swap(a, start++, beg+2);
			

		}
		return findRank(a, l, l+groups-1, groups/2);

	}




	int Partition(int a[], int low, int high, int p)
	{
		
		int l = low, r = high;
		int pivot = a[p];
		while( l <= r)
		{
			while((l<= high) && (a[l] <= pivot))
				l++;
			while((r >= low) && (a[r] > pivot))
				r--;
			if(l < r)
			{
				swap(a, l, r);
				l++;
				r--;
			}
					
		}
		return r;
	}

	int findRank(int a[], int i, int j, int r)
	{
			
		if(i == j)
		{
			return i;
		}
			
			
		int p = goodPivot(a, i, j);
			 
		int k = Partition(a, i, j, p);
		if(r == (j-k+1))
			return k;
		else if(r < (j-k+1))
			return findRank(a, k+1, j, r);
		else
			return findRank(a, i, k, r-j+k);
				
			
			
		
	}


int main()
{
/*	FILE *fp;
	fp = fopen("input","r");
	int i=0;
	for(i = 0; i < l; i++)
	{
		fscanf(fp,"%1d",&N[i]);
	}*/

	int N[10] = {4, 3, 26, 122, 56, 202, 900, 25, 78, 90};
	int l=10;

	int first = 0;
	int last = l - 1;

	int r, num;
	printf ("enter the rank=");
	scanf("%d", &r);

	num = findRank(N, first, last, r);
	printf ("The number is: %d\n", N[num]);
	//fclose(fp);
	return 0;
}
