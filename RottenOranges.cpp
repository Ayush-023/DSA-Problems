// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        list<pair<int,int>>q;int n=grid.size(),m=grid[0].size();
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==2)
                {
                    q.push_back({i,j});
                }
            }
        }
        q.push_back({-1,-1});
        int t=0;
        while(!q.empty())
        {
           pair<int,int>x=q.front();
          // cout<<"first: "<<x.first<<" || second: "<<x.second<<" \n";
           q.pop_front();
           if(x.first==-1)
           {
               if(!q.empty())
              { t++;
               q.push_back({-1,-1});}
               else
               continue;
           }
           else
           {
               int first=x.first,second=x.second;
               if(first+1<n)
               {
                   if(grid[first+1][second]==1)
                  { q.push_back({first+1,second});
                   grid[first+1][second]=2;}
               }
               if(second+1<m)
               {
                   if(grid[first][second+1]==1)
                  { q.push_back({first,second+1});
                   grid[first][second+1]=2;}
               }
               if(first-1>=0)
               {
                   if(grid[first-1][second]==1)
                  { q.push_back({first-1,second});
                   grid[first-1][second]=2;}
               }
               if(second-1>=0)
               {
                   if(grid[first][second-1]==1)
                  { q.push_back({first,second-1});
                   grid[first][second-1]=2;
                     // cout<<"x: "<<first<<" ";
                  }
               }
           }
        }
        bool ans=true;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==1)
                {
                        ans=0;break;
                }
            }
            if(!ans)
            {
                break;
            }
        }
        if(ans)
        return t;
        else 
        return -1;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends