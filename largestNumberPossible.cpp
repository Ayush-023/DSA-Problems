// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        if(S==0&&N>1)
        return "-1";
        string s="";
        while(N--)
        {
            int i=9;
            while(true)
            {
                if(S-i>=0)
                {
                    S-=i;
                    s+=to_string(i);
                    break;
                }
                i--;
            }
        }
        if(S>0)
        return "-1";
        
        return s;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends