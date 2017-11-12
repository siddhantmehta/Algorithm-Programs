/*Find the number which has the given rank (rank is given as input). Use random pivot algorithm*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int first, last;
int N[1000000],l = 1000000;

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
	FILE *fp;
	fp = fopen("input","r");
	int i=0;
	for(i = 0; i < l; i++)
	{
		fscanf(fp,"%1d",&N[i]);
	}

	//int N[7] = {4, 3, 26, 122, 56, 202, 900};
	//int l=7;

	first = 0;
	last = l - 1;

	int r, num;
	printf ("enter the rank=");
	scanf("%d", &r);

	num = rank(N, first, last, r);
	printf ("The number is: %d", num);
	fclose(fp);
	return 0;
	
}
