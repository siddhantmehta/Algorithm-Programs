/*Find the smallest k elements in a array. Read 2k elements. Find the medians and then apply partition. The value more than k is not the candidate, then overwrite the next k elements from k to 2k again find median and repeat */

#include<stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int partition(int *N, int l, int r, int p){
	int i=l-1, j=l;
	if (l==r)
		return l;

	//swap N[p] and N[r]
	int temp;
	temp = N[p];
	N[p] = N[r];
	N[r] = temp;

	while (j<r)
	{
		if (N[j] <=N[r])
		{
			i=i+1;
			//swap N[i] and N[j]
			temp = N[j];
			N[j] = N[i];
			N[i] = temp;
		}
		j++;
	}
	i=i+1;
	//swap N[i] and N[r];
	temp = N[i];
	N[i] = N[r];
	N[r] = temp;
	return i;
}

int rank(int *N, int i, int j, int r){
	int p = rand() % (j-i+1) + i;
	int k = partition (N, i, j, p);
	if (r == j-k+1)
	{
		return N[k];
	}
	else if (r < j-k+1)
	{
		rank(N, k+1, j, r);
	}
	else
	{
		rank(N, i, k-1, (r-j+k-1));		
	}
}

int main()
{
/*	int a[16]={17,7,2,34,19,0,64,0,73,35,5,1,8,88,4,6};
	int k = 4;
	int n=16, i, med;
	int c[8];*/

	int k=10000;
	int n=1000000;
	int i, med;
	int a, c[20000] = {0};

	FILE *fp;
	fp = fopen("input","r");
	for(i = 0; i < 2*k; i++)
	{
		fscanf(fp,"%1d",&c[i]);
	}

	for(i = 0; i < 2*k; i++)
	{
		printf("%d\t",c[i]);
	}

/*	for (int i = 0; i < 2*k; i++)
	{
		c[i]=a[i];
	}*/

	med=rank(c,0,2*k-1,k);
	

	for (i = 2*k; i < n; i++)
	{
		//printf("Debuging\n");
		fscanf(fp, "%1d", &a);
		for (int j = k; j <2*k ; j++)
		{
			if(i<n)
			{
				//c[j] = a[i];
				//i++;
				c[j] = a;
				fscanf(fp, "%1d", &a);
				i++;
			}
		}
		fseek(fp, -1, 1);
		i--;
		med=rank(c,0,2*k-1,k);
	}

	for(i=0; i<k; i++)
	{
		printf("%d\t", c[i]);
	}
	printf("\n");

	fclose(fp);

}
