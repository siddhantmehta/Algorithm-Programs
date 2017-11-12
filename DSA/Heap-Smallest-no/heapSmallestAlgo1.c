/*Find smallest k elements in a array. Create a max. heap with k numbers. Then compare the max. and go from k+1 to n. If the no. is less than max. replace with max. of heap and call max. heap again, else throw it. Space-O(k). Time- O(nlgk)*/

#include<stdio.h>

void topDownHeapify(int *A, int i, int n)
{
			//printf("Debugging\n");
	while(((2*i)+1) < n)
	{
		int l, r, m, temp;
		l=(2*i)+1;
		r=(2*i)+2;
		
		if((r<n) && (A[l]>A[r]))
			m=r;
		else
			m=l;

		if(A[i]>A[m])
		{
			//swap A[i], A[m]
			temp = A[i];
			A[i] = A[m];
			A[m] = temp;
			i=m;
		}
		else
		{
			break;
		}
	}
}

void buildHeap(int *c, int k)
{	
	int i;
	for (i=k/2; i>=0; i--)
	{
		//printf("Debugging\n");
		topDownHeapify(c, i, k);
	}
}

int main()
{
	//int a[10]={17,7,2,34,19,15,64,54,73,35};
	//int k = 4, n=10;
	//int c[4]={0};

	int c[10000] = {0};
	int k=10000;
	int n=1000000;
	int a;


	FILE *fp;
	fp = fopen("input","r");
	int i=0;
	for(i = 0; i < k; i++)
	{
		fscanf(fp,"%1d",&c[i]);
	}

/*	for (i=0; i<k; i++)
	{
		c[i] = a[i];
	}*/

	buildHeap(c,k);

/*	for(i=0; i<k; i++)
	{
		printf("%d\t", c[i]);
	}
	printf("\n");*/
	
	for (i=k; i<n; i++)
	{
		fscanf(fp, "%1d", &a);
		//printf("C[0]=%d, a[i]=%d\n", c[0], a[i]);
		if(c[0] > a)
		{
			//printf("Entering\n");
			c[0]=a;
			buildHeap(c,k);
		}
/*		for(int j=0; j<k; j++)
		{
			printf("%d\t", c[j]);
		}
		printf("\n");*/
	}	

	for(i=0; i<k; i++)
	{
		printf("%d\t", c[i]);
	}
	printf("\n");
	fclose(fp);
}
