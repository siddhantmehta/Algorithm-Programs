//Dijkstra's Algorithm. Adjacency matrix is used to represent the graph

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define VERT 3

int minDist(int dist[], int checkVert[])
{
	int minDist = INT_MAX, vertex;
   	for (int v = 0; v < VERT; v++)
	{
     		if (checkVert[v] == 0 && dist[v] <= minDist)
		{
         		minDist = dist[v];
			vertex = v;
		}
	}
  
   return vertex;
}

void dijkstra(int adjMat[][VERT], int s)
{
	int dist[VERT];
	int checkVert[VERT];	//included in shortest path tree or not

	for (int i = 0; i < VERT; i++)
	{
		dist[i] = INT_MAX;
		checkVert[i] = 0;	
	}

	dist[s] = 0;
	for (int i = 0; i < VERT-1; i++)
	{
		int u = minDist(dist, checkVert);	//vertex with minimum distance
		checkVert[u] = 1;
		//printf("Distance of u %d\n", dist[u]);
		for (int v=0; v<VERT; v++)
		{
			if((!checkVert[v]) && (adjMat[u][v]) && (dist[u] != INT_MAX) && (dist[u]+adjMat[u][v] < dist[v]))
			{	
				 dist[v] = dist[u]+adjMat[u][v];
			}
		}
	}

	for (int i=0; i<VERT; i++)
	{
		printf("Vertex = %d, distance = %d\n", i, dist[i]);
	}

}

int main()
{
	int i, j, weight;
	int adjMat[VERT][VERT] = {0};

	for (i=0; i<VERT; i++)
	{
		for (j=i+1; j<VERT; j++)
		{
			printf("Enter the weight of vertices %d and %d : ", i, j);
			scanf("%d", &weight);
			adjMat[i][j] = weight;
			adjMat[j][i] = weight;
		}
	}

/*	for (i=0; i<VERT; i++)
	{
		for (j=0; j<VERT; j++)
		{
			printf("%d\t", adjMat[i][j]);
		}
		printf("\n");
	}*/

	dijkstra(adjMat, 0);

	return 0;

}
