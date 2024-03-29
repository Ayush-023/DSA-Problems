// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
    int minOperation(int n)
    {
        vector<int>dp(n+1);
        dp[0]=0;
        
        for(int i=1;i<=n;i++)
        {
            int one=-1,two=INT_MAX;
            if(i%2==0)
            {
                two = dp[i/2]+1;
            }
            one = dp[i-1]+1;
            
            dp[i]=min(one,two);
        }
        
        return dp[n];
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        Solution ob;
	        cout<<ob.minOperation(n)<<endl;
	    }
}  // } Driver Code Ends