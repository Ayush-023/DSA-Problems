// { Driver Code Starts
// Driver code

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
  public:
    int findOnce(int arr[], int n)
    {
        int l=0,r=n-1,m;
        
        while(l<=r)
        {
            m=l+(r-l)/2;
            bool parity = m%2;
            
            if(parity)
            {
                if(arr[m]==arr[m-1])
                {
                    l=m+1;
                }
                else if(arr[m]==arr[m+1])
                {
                    r=m-1;
                }
            }
            else
            {
                if(m-1<0||m+1>=n)
                {
                    return arr[m];
                }
                if(arr[m]==arr[m-1])
                {
                    r=m-1;
                }
                else if(arr[m]==arr[m+1])
                {
                    l=m+1;
                }
                else
                return arr[m];
            }
        }
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
        int A[n];
        for(int i = 0;i < n;i++)
        {
            cin>>A[i];
        }
        
        Solution ob;
        
        int res = ob.findOnce(A,n);
        cout << res << endl;
    }
    
    return 0;
}  // } Driver Code Ends