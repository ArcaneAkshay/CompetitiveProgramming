// BFS uses an iterative approach
// It's like level order traversal in a tree
// Single source shortest path using BFS Graphs
// means the shortest path of a anode form another node
// Distance calculated by a level order traversal is the shortest if the graph is an unweighted graph
// Relative Level of that node(another node) w.r.t the source node is the required distance 
// In case of Weighted graphs we use Dijiktras algorithm to calculate shartest path from one node to another node
// DFS is a recursive approach to traverse a graph
#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<climits>
#include<vector>
using namespace std;

template<typename T>
class Graph
{
	map<T,list<T>> l;
public:
	void addEdge(int x, int y)
	{
		l[x].push_back(y);
		l[y].push_back(x);
	}

	void bfs(T src)
	{
		map<T,int> visited;
		queue<T> q;

		q.push(src);
		visited[src] = true;

		while(!q.empty())
		{
			T node = q.front();
			q.pop();
			cout<<node<<" ";
			for(int nbr: l[node])
			{
				if(!visited[nbr])
				{
					q.push(nbr);
					// Mark the node as visited
					visited[nbr] = true;
				}
			}
		}
	}

	void singleSourceShortestPath_BFS(T src)
	{
		map<T,int> dist;
		queue<T> q;

		// All other node except source node will have INT_MAX distance
		// So we're updating the distance of all other nodes as INT_MAX
		for(auto node_pair:l)
		{
			T node = node_pair.first;
			dist[node] = INT_MAX;
		}
		q.push(src);
		dist[src] = 0; // Source will have 0 distance

		while(!q.empty())
		{
			T node = q.front();
			q.pop();
			//cout<<node<<" ";
			for(int nbr: l[node])
			{
				if(dist[nbr]==INT_MAX)
				{
					q.push(nbr);
					// Mark the node as visited
					dist[nbr] = dist[node]+1;
				}
			}
		}

		//Print the dist to every node
		for(auto node_pair:l)
		{
			T node = node_pair.first;
			int d = dist[node];
			cout<<"Node "<<node<<" Distance from src "<<d<<"\n";
		}
	}

	void dfsHelper(T src ,map<T,bool> &visited)
	{
		// Recursive function that will traverse the graph

		cout<<src<<" ";
		visited[src] = true;
		// Go to all teh neighbours of the node that is not visited
		for(T nbr:l[src])
		{
			if(!visited[nbr])
			{
				if(!visited[nbr])
					dfsHelper(nbr,visited);
			}
		}
	}

	void dfs(T src)
	{
		map<T,bool> visited;
		
		// Mark all the nodes as not visited in the beginning
		for(auto p:l)
		{
			T node = p.first;
			visited[node] = false;
		}
		dfsHelper(src, visited);
	}

	// Here undirected graph is referred
	// In a Connected graph there exits at least one path between every pair of vertices
	// To calculate the no. of components in a graph



	// An Undirected Graph contains a cycle if there is more than one way to visit a node
	// We can use both BFS and DFS
	// Here we are using DFS


	bool cycle_helper(int node, bool *visited, int parent)
	{
		visited[node] = true;

		for(auto nbr:l[node])
		{
			//Two cases
			if(!visited[nbr])
			{
				// Go and recursively the nbr
				bool foundCycle = cycle_helper(nbr,visited,node);
				if(foundCycle)
					return true;
			}
			// nbr is visited but nbr should not be equal to parent
			else if(nbr!=parent)
			{
				return true;
			}
		}
		return false;
	}

	bool detectCycle()
	{
		// Number of vrtices in the graph
		int V = 6;
		// Check for the cycle in undirected graph
		bool *visited = new bool[V];
		for(int i=0;i<V;i++)
		{
			visited[i] = false;
		}
		return cycle_helper(0, visited, -1);
	}
};

int main()
{
	Graph<int> g;

	g.addEdge(0,1);
	// g.addEdge(0,3); // If I uncomment this then the answer is one(true) for detectCycle() why?
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(4,5);

	//g.bfs(0);
	//g.singleSourceShortestPath_BFS(0);
	//g.dfs(0);
	cout<<g.detectCycle();
	return 0;
}