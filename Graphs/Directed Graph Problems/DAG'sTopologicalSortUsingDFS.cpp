#include<iostream>
#include<map>
#include<list>
#include<string>
using namespace std;

template<typename T>
class Graph
{
	map<T,list<T>> l;
public:
	void addEdge(T x, T y)
	{
		l[x].push_back(y);
		//l[y].push_back(x); No need of this statement since the graph is directed
	}

	void dfsHelper(T src ,map<T,bool> &visited,list<T> &ordering) // List is passed by reference since we noeed to update only a single list containing the required order
	{
		// Recursive function that will traverse the graph

		//cout<<src<<" ";
		// Mark the current node as visited
		visited[src] = true;
		// Go to all the neighbours of the node that is not visited
		for(T nbr:l[src])
		{
			if(!visited[nbr])
			{
				if(!visited[nbr])
					dfsHelper(nbr,visited, ordering);
			}
		}
		// Added in existing dfs
		ordering.push_front(src);
		return;
	}

	void dfs(T src)
	{
		map<T,bool> visited;
		list<T> ordering; //  and this is added in existing dfs
		// Mark all the nodes as not visited in the beginning
		for(auto p:l)
		{
			T node = p.first;
			visited[node] = false;
		}
		// ================= This is added in the existing dfs =======================
		//dfsHelper(src, visited);
		// Call the helper function from all the nodes to make sure that no node is left unvisited
		// this is because it is possible that we have more than one node with no dependency
		// this will help us make sure that the dependencies of all the nodes with no dependencies are included in the ordering list
		for(auto p:l)
		{
			T node = p.first;
			if(!visited[node])
			{
				dfsHelper(node,visited,ordering);
			}
		}

		//Print the list
		for(auto node:ordering)
			cout<<node<<endl;

		// OR return list(if list is declared globally)
		// ===========================================================================
	}

	// Topological sort function is nothing but a modified dfs in which we store the nodes as we traverse in appropriate manner( i.e. using push_front());
	void topologicalSort(T src)
	{
		dfs(src);
	}
};

int main()
{
	Graph<string> g;

	// g.addEdge(0,1);
	// // g.addEdge(0,3);
	// g.addEdge(1,2);
	// g.addEdge(2,3);
	// g.addEdge(3,4);
	// g.addEdge(4,5);

	//g.bfs(0);
	//g.singleSourceShortestPath_BFS(0);
	//g.dfs(0);
	
	g.addEdge("Python","DataProcessing");
	g.addEdge("Python","PyTorch");
	g.addEdge("Python","ML");
	g.addEdge("DataProcessing","ML");
	g.addEdge("PyTorch","DL");
	g.addEdge("ML","DL");
	g.addEdge("DL","FaceRecogn");
	g.addEdge("DataSet","FaceRecogn");

	g.topologicalSort("Python");
	return 0;
}