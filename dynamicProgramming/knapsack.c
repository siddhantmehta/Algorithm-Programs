#include<stdio.h>
int main()
{
	int n;
	printf("Enter the number of items:");
	scanf("%d",&n);
	int weights[n],values[n];
	for(int i=0;i<n;i++)
	{
		printf("Enter weight:");
		scanf("%d",&weights[i]);
		printf("Enter value:");
		scanf("%d",&values[i]);
	}
	/*for (int i = 0; i < n; ++i)
	{
		printf("weights %d\n",weights[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		printf("values %d\n",values[i] );
	}*/
	int capacity;
	printf("Enter capacity:");
	scanf("%d",&capacity);
	int dpTable[n][capacity+1];
	for(int j=0;j<capacity+1;j++)
	{
		if(j>=weights[0])
		{
			dpTable[0][j]=values[0];
		}
		else
			dpTable[0][j]=0;
	}
	for (int i = 0; i < n; ++i)
	{
		dpTable[i][0]=0;
	}
	int i=1;
	int j=1;
	while(j<capacity+1)
	{
		i=1;
		while(i<n)
		{
			dpTable[i][j]=dpTable[i-1][j];
			if(j>=weights[i] && dpTable[i][j]<values[i]+dpTable[i-1][j-weights[i]])
			{
				dpTable[i][j]=values[i]+dpTable[i-1][j-weights[i]];
			}
			i++;
		}
		j++;
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < capacity+1; ++j)
		{
			printf("%d ",dpTable[i][j]);
		}
		printf("\n");
	}
	printf("Maximum profit :%d\n",dpTable[n-1][capacity]);
	i=n-1;
	j=capacity;
	while(i>0 || j>0)
	{
		if(i!=0 && dpTable[i][j]==dpTable[i-1][j])
		{
			i--;
		}
		else
		{
			printf("%d %d\n",weights[i],values[i]);
			j=j-weights[i];
			i--;
		}
	}
	return 0;
}