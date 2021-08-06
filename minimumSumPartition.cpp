// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    long long sum=0;
	    for(int i=0;i<n;i++)
	    {
	        sum+=arr[i];
	    }
	    
	    long long N=0;
	    
	    if(sum%2)
	    N=(sum-1)/2;
	    else
	    N = sum/2;
	    
	    vector<vector<int>>dp(N+1,vector<int>(n+1,0));
	    for(int i=0;i<=N;i++)
	    dp[i][0]=0;
	    
	    for(int i=0;i<=n;i++)
	    dp[0][i]=1;
	    
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=1;j<=N;j++)
	        {
	            dp[j][i]=dp[j][i-1];
	            if(j>=arr[i-1])
	            {
	                dp[j][i]=max(dp[j][i],dp[j-arr[i-1]][i-1]);
	            }
	        }
	    }
	   // cout<<N<<" :: ";
	    int i=N,diff=0;
	    while(i>=0)
	    {
	        if(dp[i][n])
	        {
	            diff=(sum-i)-i;
	            break;
	        }
	        else
	        i--;
	    }
	    return diff;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends