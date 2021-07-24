// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool isValid(int x,int y,int n)
    {
        return (x>=0&&y>=0&&x<n&&y<n);
    }
    
    bool is_Possible(vector<vector<int>>& grid) 
    {
  
        pair<int,int>s{-1,-1},d{-1,-1};
        int n = grid.size();
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==1)
                    s = {i,j};
                    
                else if(grid[i][j]==2)
                    d = {i,j};
            }
        }
        
        if(s.first==-1||d.first==-1)
            return false;
        
        
        int xx[] = {0,-1,0,1};
        int yy[] = {-1,0,1,0};
        
        // vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size()));
        bool vis[grid.size()][grid[0].size()];
        memset(vis, false, sizeof(vis));
        
        vis[s.first][s.second]=true;
        
        queue<pair<int,int>>q;
        q.push(s);
        
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            
            if(it.first==d.first&&it.second==d.second)
                {
                    return true;
                    break;
                }
                
            for(int i=0;i<4;i++)
            {
                if(isValid(it.first+xx[i],it.second+yy[i],n)&&!vis[it.first+xx[i]][it.second+yy[i]]&&grid[it.first+xx[i]][it.second+yy[i]]!=0)
                {
                    vis[it.first+xx[i]][it.second+yy[i]]=true;
                    q.push({it.first+xx[i],it.second+yy[i]});
                }
            }
        }
        
        return false;
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
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends