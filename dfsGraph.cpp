// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution 
{
    public:
	//Function to return a list containing the DFS traversal of the graph.
	void dfs(vector<int> adj[],vector<bool>&vis,int x,vector<int>&v)
	{
	    if(!vis[x])
	    {
	        vis[x]=true;
	        v.push_back(x);
	        
	        for(int i=0;i<adj[x].size();i++)
	        {
	            for(auto j=adj[x].begin();j!=adj[x].end();j++)
	            dfs(adj,vis,*j,v);
	        }
	    }
	}
	
	vector<int>dfsOfGraph(int V, vector<int> adj[])
	{
	    vector<bool>vis(V,false);vector<int>v;
	    
	    dfs(adj,vis,0,v);
	    
	    return v;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.dfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  // } Driver Code Ends