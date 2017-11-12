/* Breadth First Serach Traversal */

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
	void BFSDisp(int p)
	{
		bool *visited = new bool[vert];
		for (int i=0; i<vert; i++)
		{
			visited[i] = false;
		}
		list<int> q;
		visited[p] = true;
		q.push_back(p);
		
		list<int>::iterator k;
		
		while(!q.empty())
		{
			p = q.front();
			cout<<p<<endl;
			q.pop_front();
			for(k = adjList[p].begin(); k != adjList[p].end(); k++)
        		{
            			if(!visited[*k])
            			{
                			visited[*k] = true;
                			q.push_back(*k);
            			}
        		}
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

	g.BFSDisp(2);

	return 0;
}
