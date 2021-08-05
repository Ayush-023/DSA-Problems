// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int n, int arr[])
    {
        // vector<vector<int>>sum(N,vector<int>(N,0));
        long long sum=0;
        
        for(int i=0;i<n;i++)
        sum+=arr[i];
        
        if(sum%2)
        return 0;
        
        vector<vector<int>>dp((sum/2)+1,vector<int>(n+1));
        
        for(int i=0;i<(sum/2)+1;i++)
        {
            dp[i][0]=0;
        }
        
        for(int i=0;i<=n;i++)
            dp[0][i]=1;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum/2;j++)
            {
                dp[j][i]=dp[j][i-1];
                if(j>=arr[i-1])
                {
                    dp[j][i]=max(dp[j][i],dp[j-arr[i-1]][i-1]);
                }
            }
        }
        if(dp[sum/2][n]>0)
        {
            return 1;
        }
        return 0;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends