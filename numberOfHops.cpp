// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        // vector<long long>dp(n+1,0);
        long long mod=1000000007;
        // dp[0]=1;
        
        // vector<int>jumps{1,2,3};
        
        long long one=1,two=1,three=2,val=1;
            for(int j=3;j<=n;j++)
            {
                // for(int i=0;i<3;i++){
                // if(j>=jumps[i])
                val=(((one+two+three)%mod)+mod)%mod;
                one=two;
                two=three;
                three=val;
                
            // }
            }
        // cout<<dp[1]<<" | "<<dp[2]<<" | "<<dp[3]<<" | ";
        if(n==2)
        return 2;
        return ((val%mod)+mod)%mod;
    }
};


// { Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}
  // } Driver Code Ends