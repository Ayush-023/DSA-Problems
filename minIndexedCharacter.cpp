// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find the minimum indexed character.
    int minIndexChar(string str, string patt)
    {
        unordered_map<int,int>u;
        
        for(int i=0;i<patt.length();i++)
        {
            if(u.find(int(patt[i]))==u.end())
            {
                u[int(patt[i])]=i;
            }
        }
        
        int earliest = INT_MAX;
        for(int i=0;i<str.size();i++)
        {
            if(u.find(int(str[i]))!=u.end())
            {
                earliest=min(earliest,i);
            }
        }
        if(earliest==INT_MAX)
        return -1;
        
        return earliest;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
    cin>>t;
    while(t--)
    {
        string str;
        string patt;
        cin>>str;
        cin>>patt;
        Solution obj;
        cout<<obj.minIndexChar(str, patt)<<endl;
    }
	return 0;
}
  // } Driver Code Ends