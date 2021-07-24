// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	void dfs(vector<int> adj[],int x, bool &flag,vector<int>&vis)
	{
	    vis[x]=1;
	    
	    for(int j:adj[x])
	    {
	        if(vis[j]==0)
	        dfs(adj,j,flag,vis);
	        else if(vis[j]==1)
	        flag=true;
	    }
	    vis[x]=2;
	}
	
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	vector<int>vis(V,0);
	   	bool flag = false;
	   	for(int i=0;i<V;i++)
	   	{
	   	    if(vis[i]==0)
	   	    dfs(adj,i,flag,vis);
	   	}
	   	return flag;
	}
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends