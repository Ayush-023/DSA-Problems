// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        vector<vector<int>>dp(N,vector<int>(N,0));
        
        for(int i=0;i<N;i++)
        dp[0][i]=Matrix[0][i];
        
        for(int i=1;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                int one=-1,two=-1,three=-1;
                
                if(i-1>=0)
                one=dp[i-1][j];
                
                if(i-1>=0&&j-1>=0)
                two=dp[i-1][j-1];
                
                if(i-1>=0&&j+1<N)
                three=dp[i-1][j+1];
                
                dp[i][j]=max(max(one,two),three)+Matrix[i][j];
            }
        }
        int largest=0;
        for(int i=0;i<N;i++)
        {
            largest=max(largest,dp[N-1][i]);
        }
        return largest;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends