// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
public:
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c)
    {
        vector<vector<bool>>vis(r,vector<bool>(c));
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            vis[i][j]=false;
        }
        vector<int>res;
        int x=(r+c)/2;
        x=x/2;

        // cout<<matrix[i][j]<<" ";
        for(int i=0;i<=x;i++)
        {
            for(int j=i;j<c-1;j++)
            {
                // if(i==1&&j==1)
                // cout<<matrix[i][j]<<" ";
                if(i>=r)
                break;
                if(!vis[i][j])
                res.push_back(matrix[i][j]);
                vis[i][j]=true;
            }
            for(int j=i;j<r-1;j++)
            {
                if(c-1-i<0)
                break;
                if(!vis[j][c-1-i])
                res.push_back(matrix[j][c-1-i]);
                vis[j][c-1-i]=true;
            }
            for(int j=c-1;j>0;j--)
            {
                if(r-1-i<0)
                break;
                if(!vis[r-i-1][j])
                res.push_back(matrix[r-i-1][j]);
                vis[r-i-1][j]=true;
            }
            for(int j=r-1;j>0;j--)
            {
                if(i>=c)
                break;
                if(!vis[j][i])
                res.push_back(matrix[j][i]);
                vis[j][i]=true;
            }
        }
        return res;
    }

};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;

    while(t--)
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r);

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
