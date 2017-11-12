/* Depth First Serach Traversal */

#include <iostream>
#include <list>

using namespace std;

class graph
{
	public:
	int vert;
	list<int> *adjList;
	graph(int vert)
	{
		this->vert = vert;
		adjList = new list<int>[vert];
	}
	void addEdge(int u, int v)
	{
		adjList[u].push_back(v);
	}
	void DFSDisp(int i, bool *visited)
	{
		visited[i] = true;
		cout<<i<<endl;
		list<int>::iterator k;
		for (k = adjList[i].begin(); k != adjList[i].end(); k++)
		{
			if(visited[*k] == false)
				DFSDisp(*k, visited);
		}
	}
	void DFSVisit()
	{
		bool *visited = new bool[vert];
		for (int i=0; i<vert; i++)
			visited[i] = false;
		for (int i=0; i<vert; i++)
		{
			if (visited[i] == false)
				DFSDisp(i, visited);
		}
	}
};

int main()
{
	graph g(4); //genaralize
	//Take edge from user
	g.addEdge(0, 2);
    	g.addEdge(0, 3);
    	g.addEdge(1, 3);
    	g.addEdge(3, 0);
    	g.addEdge(3, 2);
   	g.addEdge(2, 1);

	g.DFSVisit();

	return 0;
}
