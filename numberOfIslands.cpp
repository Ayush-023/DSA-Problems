// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:

  void dfs(vector<vector<char>>&grid,vector<vector<bool>>&vis,int i,int j)
    {
         if(i<0&&i>=grid.size()&&j<0&&j>=grid[0].size())
         return;
        
        if(grid[i][j]=='1')
        vis[i][j] = true;
        
        else
        return;
        
        if(i-1>=0)
        {
            if(!vis[i-1][j])
            {
                dfs(grid,vis,i-1,j);
            }
            if(j+1<grid[0].size())
            {
                if(!vis[i-1][j+1])
                {
                    dfs(grid,vis,i-1,j+1);
                }
            }
            
        }
        
        if(i+1<grid.size())
        {
            if(!vis[i+1][j])
            {
                dfs(grid,vis,i+1,j);
            }
            if(j-1>=0)
            {
                if(!vis[i+1][j-1])
                {
                    dfs(grid,vis,i+1,j-1);
                }
            }
        }
        
        if(j-1>=0)
        {
            if(!vis[i][j-1])
            {
                dfs(grid,vis,i,j-1);
            }
            
            if(i-1>=0)
            {
                if(!vis[i-1][j-1])
                {
                    dfs(grid,vis,i-1,j-1);
                }
            }
        }
        
        if(j+1<grid[0].size())
        {
            if(!vis[i][j+1])
            {
                dfs(grid,vis,i,j+1);
            }   
            if(i+1<grid.size())
            {
                if(!vis[i+1][j+1])
                {
                    dfs(grid,vis,i+1,j+1);
                } 
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) 
    {
        int n = grid.size(), m = grid[0].size();
       
        int count = 0;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                if(!vis[i][j]&&grid[i][j]=='1')
                {
                    // cerr<<"i: "<<i<<" j: "<<j<<" || ";
                    dfs(grid,vis,i,j);
                    count++;
                }
        }
        
        return count;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.numIslands(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends