//Bellman Ford

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Edge
{
	int src, dest, weight;
};

struct Graph
{
	int V, E;
	struct Edge* edge;
};

struct Graph* createGraph(int V, int E)
{
    	struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    	graph->V = V;
    	graph->E = E;
    	graph->edge = (struct Edge*) malloc(graph->E * sizeof(struct Edge));
    	return graph;
};

void bellmanFord(struct Graph* graph, int src)
{
	int Vert = graph->V;
	int Edge = graph->E;
	int dt[Vert];

	for (int i=0; i<Vert; i++)
		dt[i] = INT_MAX;
	dt[src] = 0;

	for(int i=1; i<Vert-1; i++)
	{
		for (int j=0; j<Edge; j++)
		{
            		int x = graph->edge[j].src;
            		int y = graph->edge[j].dest;
            		int wt = graph->edge[j].weight;
            		if (dt[x] != INT_MAX && dt[x] + wt < dt[y])
                		dt[y] = dt[x] + wt;
		}
	}

	for (int j=0; j<Edge; j++)
	{
           	int x = graph->edge[j].src;
            	int y = graph->edge[j].dest;
            	int wt = graph->edge[j].weight;
            	if (dt[x] != INT_MAX && dt[x] + wt < dt[y])
                	printf("Presence of Negative cycle\n");
	}

	for (int i=0; i<Vert; i++)
	{
		printf("Vertex = %d, dist. from source = %d\n", i, dt[i]);
	}
}

int main()
{
	int Vert = 5;
	int Edge = 8;
	struct Graph* creategraph = createGraph(Vert, Edge);	


	for (int i=0; i<Edge; i++)
	{	
		printf("Enter the source of edge:");
		scanf("%d", &creategraph->edge[i].src);
		printf("Enter the destination of edge:");
		scanf("%d", &creategraph->edge[i].dest);
		printf("Enter the weight of edge:");
		scanf("%d", &creategraph->edge[i].weight);
	}

	bellmanFord(creategraph, 0);

	return 0;
}
