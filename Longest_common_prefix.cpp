// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
    string longestCommonPrefix (string arr[], int n)
    {
        string pre=arr[0];
        for(int i=1;i<n;i++)
        {
            string s=arr[i],temp="";int ss=s.size()<pre.size()?s.size():pre.size();
            for(int j=0;j<ss;j++)
            {
                if(s[j]==pre[j])
                {
                    temp+=s[j];
                    continue;
                }
                else
                {
                    break;
                }
            }
            if(temp.empty())
            temp="-1";
            pre=temp;
        }
        return pre;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends