//Kruskal's Algorithm

#include <stdio.h>
#include <stdlib.h>


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

struct subGraph
{
    	int parent;
    	int rank;
};

int find(struct subGraph subGraphs[], int r)
{
    	if (subGraphs[r].parent != r)
        	subGraphs[r].parent = find(subGraphs, subGraphs[r].parent);
    	return subGraphs[r].parent;
}

void Union(struct subGraph subGraphs[], int x, int y)
{
    	int xroot = find(subGraphs, x);
    	int yroot = find(subGraphs, y);
    	//smaller rank tree is attached the under root of high rank tree
    	if (subGraphs[xroot].rank < subGraphs[yroot].rank)
        	subGraphs[xroot].parent = yroot;
    	else if (subGraphs[xroot].rank > subGraphs[yroot].rank)
        	subGraphs[yroot].parent = xroot;
    	else
    	{
        	subGraphs[yroot].parent = xroot;
        	subGraphs[xroot].rank++;
    	}
}

int compare(const void* x, const void* y)
{
    	struct Edge* x1 = (struct Edge*)x;
    	struct Edge* y1 = (struct Edge*)y;
    	return x1->weight > y1->weight;
}

void kruskals(struct Graph* graph)
{
    int V = graph->V;
    struct Edge newGraph[V];  
    int e = 0;  
    int i = 0;  
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), compare);
    struct subGraph *subGraphs = (struct subGraph*) malloc( V * sizeof(struct subGraph) );
    for (int i = 0; i<V; i++)
    {
        subGraphs[i].parent = i;
        subGraphs[i].rank = 0;
    }
    while (e < V - 1)
    {
        struct Edge nextEdge = graph->edge[i++];
 
        int x = find(subGraphs, nextEdge.src);
        int y = find(subGraphs, nextEdge.dest);

        if (x != y)
        {
            newGraph[e++] = nextEdge;
            Union(subGraphs, x, y);
        }
    }

    printf("Edges in Kruskals MST\n");
    for (i = 0; i < e; ++i)
        printf("source = %d, Destination = %d, Weight = %d\n", newGraph[i].src, newGraph[i].dest, newGraph[i].weight);
    return;
}

int main()
{
	int Vert = 4;
	int Edge = 5;
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

	kruskals(creategraph);

	return 0;
}
