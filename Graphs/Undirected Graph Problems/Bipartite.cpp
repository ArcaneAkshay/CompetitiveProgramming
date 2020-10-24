#include<iostream>
#include<vector>
using namespace std;

//============= Bipartite Graph(Undirected) =============
	// Two coloring problem -> Is it possible to color all the vertices using two colors such that all ajacent vertices have different colors?
	// We can divide all the vertoces of the graph in 2 sets
	// such that edges of all the graph are between set 1 and set2 i.e. no edge exists between nodes of the same set
	// If a cycle is not present in a graph or graph is a binary tree, then it is always a Bipartite Graph
	// If a graph contains a cycle and has odd no. of nodes then there exits an edge between two node of the same set. So such graph is not a Bipartite Graph
	// Also if a graph contains a cycle such that from a vertex we're going to a node which has same color, then it is not a Bipartite Graph

	// here Array of vectors is used to construct graph
//==============================================================

bool dfs_helper(vector<int> graph[], int node, int *visited, int parent, int color)
{
	visited[node] = color; // 1 or 2, both mean visited

	for(auto nbr:graph[node])
	{
		if(visited[nbr]==0)
		{
			bool subprob = dfs_helper(graph,nbr,visited, node,3-color);

			if(!subprob) //subprob==false;
				return false;
		}
		else if(nbr!=parent and color==visited[nbr]) // Here 'color' represents the condition for odd number of nodes
			return false;
	}
	return true;
}


bool dfs(vector<int> graph[], int N)
{
	int visited[N] = {0}; // 0 -> Not Visited , 1-> Visited color is 1, 2-> Visited color is 2
	int color = 1;
	int ans = dfs_helper(graph,0,visited,-1,color);
	//later one

	// Printing colors
	for(int i=0;i<N;i++)
		cout<<i<<" - color "<<visited[i]<<endl;

	return ans;
}


int main()
{
	int N,M;
	cin>>N>>M;

	vector<int> graph[N];
	while(M--)
	{
		int x,y;
		cin>>x>>y;

		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	// BFS or DFS by coloring the nodes at each step (current node has color 1, nbr should have a color 2)
	cout<<dfs(graph,N)<<endl;
}