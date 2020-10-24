#include<iostream>
#include<vector>
#include<climits>
#include<queue>
using namespace std;

const int N = 100005, M = 22;

vector<int> graph[N];

void bfs(int src, int n, int &ans)
{
	vector<int> dist(n+1,INT_MAX);
	queue<int> Q;
	Q.push(src);
	dist[src] = 0;

	while(!Q.empty())
	{
		int cur_node = Q.front();
		Q.pop();

		for(auto nbr:graph[cur_node])
		{
			if(dist[nbr] == INT_MAX)
			{
				// nbr not visited
                dist[nbr] = dist[cur_node]+ 1;
                Q.push(nbr);
			}
			else if(dist[nbr]>=dist[cur_node])
			{
				//Backedge is encountered (Cycle)
				ans = min(ans, dist[nbr] + dist[cur_node]+1);
			}
		}

	}
}

int main()
{
	int i,j,n,m,ans;
	// n = no. of edges, m = no. of nodes
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	ans = n+1; // To represent no cycle initially 
	for(int i=1;i<=n;i++) // 1 based indexing
	{
		bfs(i,n,ans);
	}
	if(ans==n+1)
		cout<<"NO\n";
	else
		cout<<"Shortest Cycle Length = "<<ans<<endl;

	return 0;
}