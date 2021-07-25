// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
	bool valid(int x, int y, int n)
	{
	    return(x>=0&&y>=0&&x<n&&y<n);
	}
	
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        vector<vector<int>>cost(n,vector<int>(n,INT_MAX));
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        
        priority_queue<pair<int,pair<int,int>>>q;
        cost[0][0]=grid[0][0];
        q.push({-1*cost[0][0],{0,0}});
        int xx[] = {0,-1,0,1};
        int yy[] = {-1,0,1,0};
        
        while(!q.empty())
        {
            auto it = q.top();
            q.pop();
            
            if(vis[it.second.first][it.second.second])
            continue;
            
            vis[it.second.first][it.second.second]=true;
            
            for(int i=0;i<4;i++)
            {
                if(valid(it.second.first+xx[i],it.second.second+yy[i],n)&&!vis[it.second.first+xx[i]][it.second.second+yy[i]])
                {
                    if(cost[it.second.first+xx[i]][it.second.second+yy[i]]>cost[it.second.first][it.second.second]+grid[it.second.first+xx[i]][it.second.second+yy[i]])
                    {
                        cost[it.second.first+xx[i]][it.second.second+yy[i]] = cost[it.second.first][it.second.second]+grid[it.second.first+xx[i]][it.second.second+yy[i]];
                        q.push({-1*cost[it.second.first+xx[i]][it.second.second+yy[i]],{it.second.first+xx[i],it.second.second+yy[i]}});
                    }
                }
            }
        }
        if(cost[n-1][n-1]!=INT_MAX)
        return cost[n-1][n-1];
        else
        return -1;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends