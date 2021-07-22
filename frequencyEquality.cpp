// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	

    bool isEqual(vector<int>h)
    {
        bool flag=false;
        
        for(int i=0;i<25;i++)
        {
            if(h[i]==0||h[i+1]==0)
            continue;
            
            else if(h[i]!=h[i+1])
            {
                // cout<<h[i]<<" :: "<<h[i+1];
                return false;
            }
        }
        return true;
    }
    
	bool sameFreq(string s)
	{
	    vector<int>h(26,0);
	    
	    for(int i=0;i<s.length();i++)
	    {
	        h[s[i]-'a']++;
	    }
	    
	    if(isEqual(h))
        return true;
	    
	    for(int i=0;i<26;i++)
	    {
	        if(h[i]==0)
                continue;
            
            h[i]--;
            if(isEqual(h))
            return true;
            
            h[i]++;
	    }
	    
	    return false;
	}
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}


  // } Driver Code Ends