// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        vector<vector<int>>dp(m+1,vector<int>(n+1));
        
        for(int i=0;i<=m;i++)
        {
            dp[i][0]=i;
        }
        
        for(int i=0;i<=n;i++)
        {
            dp[0][i]=i;
        }
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dp[i][j]=1+min(dp[i][j-1],dp[i-1][j]);
                
                if(X[i-1]==Y[j-1])
                {
                    dp[i][j]=min(1+dp[i-1][j-1],dp[i][j]);
                }
            }
        }
        // int  x = (m<n)?m:n;
        return dp[m][n];
    }
};

// { Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}

  // } Driver Code Ends