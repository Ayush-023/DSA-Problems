// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    bool isValid(int x, int y,vector<vector<int>> &m,vector<vector<bool>> &vis)
    {
        return(x>=0&&y>=0&&x<m.size()&&y<m.size()&&m[x][y]==1&&!vis[x][y]);
    }
    
    void search(string state,vector<string>&result,vector<vector<int>> &m, int row,int col,int n,vector<vector<bool>> &vis)
    {
        if(row==n-1&&col==n-1)
        {
            result.push_back(state);
            return;
        }
        
        vector<int>x{1,0,0,-1};
        vector<int>y{0,-1,1,0};
        vector<vector<string>>map(3,vector<string>(3));
        map[0][1]="U";map[1][0]="L";map[1][2]="R";map[2][1]="D";
        
        for(int i=0;i<4;i++)
        {
            if(isValid(row+x[i],col+y[i],m,vis))
            {
                vis[row+x[i]][col+y[i]]=true;
                state+=map[x[i]+1][y[i]+1];
                
                search(state,result,m,row+x[i],col+y[i],n,vis);
                
                state.pop_back();
                vis[row+x[i]][col+y[i]]=false;
            }
        }
        return;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string>result;
        if(m[0][0]==0)
        return result;
        
        string state;
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        vis[0][0]=1;
        search(state,result,m,0,0,n,vis);
        
        return result;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends