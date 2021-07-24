// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	
	void explore(vector<int> adj[],vector<bool>&vis,vector<int>&res,int x)
	{
	    vis[x]=true;
	    
	    for(int j:adj[x])
	    {
	        if(!vis[j])
	        {
	            explore(adj,vis,res,j);
	        }
	    }
	    res.push_back(x);
	}
	void explorer(vector<int> adj[],vector<bool>&vis,int x)
	{
	    vis[x]=true;
	    
	    for(int j:adj[x])
	    {
	        if(!vis[j])
	        {
	            explorer(adj,vis,j);
	        }
	    }
	}
	
	vector<int>dfs(vector<int> adj[],int V)
	{
	    vector<bool>vis(V,false);
	    vector<int>result;
	    
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i])
	        {
	            explore(adj,vis,result,i);
	        }
	    }
	    reverse(result.begin(),result.end());
	    return result;
	}
	
    int kosaraju(int V, vector<int> adj[])
    {
        vector<int>rev[V];
        
        for(int i=0;i<V;i++)
        {
            for(int j:adj[i])
            {
                rev[j].push_back(i);
            }
        }
        
        vector<int>order = dfs(rev,V);
        int count = 0;vector<bool>vis(V,false);
        for(int i = 0;i<order.size();i++)
        {
            if(!vis[order[i]])
            {
                explorer(adj,vis,order[i]);
                count++;
            }
        }
        return count;
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
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends