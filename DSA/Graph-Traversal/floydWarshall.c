//Floyd Warshall

#include <stdio.h>
#include <limits.h>

#define V 4

void floydWarshall(int graph[][V])
{
	int dt[V][V];

	for (int i=0; i<V; i++)
	{
		for (int j=0; j<V; j++)
		{
			dt[i][j] = graph[i][j];
		}
	}

	for (int k=0; k<V; k++)
	{
		for (int i=0; i<V; i++)
		{
			for (int j=0; j<V; j++)
			{
				if (dt[i][k] != INT_MAX && dt[k][j] != INT_MAX && dt[i][k] + dt[k][j] < dt [i][j])
					dt[i][j] = dt[i][k] + dt[k][j];
			}
		}
	}

	for (int i=0; i<V; i++)
	{
		for (int j=0; j<V; j++)
		{
			printf("Edge1 = %d, Edge2 = %d, shortest dist. = %d\n", i, j, dt[i][j]);
		}
	}
}

int main()
{
	int infinite = INT_MAX;

	int graph[V][V] = {{0, 5, infinite, 10}, {infinite, 0, 3, infinite}, {infinite, infinite, 0, 1}, {infinite, infinite, infinite, 0}};

	floydWarshall(graph);
	return 0;
}
