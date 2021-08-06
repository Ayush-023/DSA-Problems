// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int>dp(n+1,-1);
        dp[0]=0;
        vector<int>cut{x,y,z};
        for(int i=0;i<3;i++)
        {
            for(int w=1;w<=n;w++)
            {
                if(w>=cut[i])
                {
                    if(dp[w-cut[i]]!=-1)
                    dp[w]=max(dp[w],dp[w-cut[i]]+1);
                }
            }
        }
        if(dp[n]==-1)
        return 0;
        
        return dp[n];
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

    return 0;
}  // } Driver Code Ends