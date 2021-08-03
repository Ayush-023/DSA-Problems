// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    // int longestSubsequence(int n, int a[])
    // {
    //   vector<int>dp(n,1);
    //   dp[0]=1; int lon=0;
       
    //   for(int i=1;i<n;i++)
    //   {
    //       for(int j=0;j<i;j++)
    //       {
    //           if(a[j]<a[i]&&dp[i]<1+dp[j])
    //           {
    //               dp[i]=dp[j]+1;
    //               lon = max(lon,dp[i]);
    //           }
               
    //       }
    //   }
    //   return lon;
    // }
    
    int longestSubsequence(int n, int a[])
    {
      int length=1;
      vector<int>tail(n,0);
      tail[0]=a[0];
      
      for(int i=1;i<n;i++)
      {
          if(a[i]<tail[0])
          tail[0]=a[i];
          
          else if(tail[length-1]<a[i])
          {
              tail[length++]=a[i];
          }
          
          else 
          {
            //   cout<<lower_bound(tail.begin(),tail.begin()+length-1,a[i])-tail.begin()<<" | ";
             tail[lower_bound(tail.begin(),tail.begin()+length-1,a[i])-tail.begin()]=a[i];
          }
      }
      return length;
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends