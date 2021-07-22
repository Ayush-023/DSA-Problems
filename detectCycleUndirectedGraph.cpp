// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
    void dfs(vector<int>adj[],vector<bool>&vis,bool &flag,int x,int parent)
    {
            vis[x]=true;
            
            for(int j : adj[x])
            {   
                if(!vis[j])
                dfs(adj,vis,flag,j,x);
                
                else if(j!=parent)
                {flag = true;}
            }
    }
        
    
	bool isCycle(int V, vector<int>adj[])
	{
	    vector<bool>vis(V,false);
	    bool t =false;
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i])
	        dfs(adj,vis,t,i,-1);
	    }
	    
	    return t;
	}
	
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends