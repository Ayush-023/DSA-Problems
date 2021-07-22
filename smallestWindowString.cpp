// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        vector<int>h(256,0),sh(256,0);
        
        int lenP = p.length(),lenS = s.length();
        
        if(lenS<lenP)
        {
            return "-1";
        }
        
        for(int i=0;i<p.length();i++)
        {
            h[p[i]-'a']++;
        }
        
        
        int count = 0, start=0, starting_index = -1,minLength = INT_MAX;
        for(int i=0;i<s.length();i++)
        {
            sh[s[i]-'a']++;
            
            if(sh[s[i]-'a']<=h[s[i]-'a'])
            {
                count++;
            }
            
            if(count==lenP)
            {
                while(sh[s[start]-'a']>h[s[start]-'a']||h[s[start]-'a']==0)
                {
                    if(sh[s[start]-'a']>h[s[start]-'a'])
                    {
                        sh[s[start]-'a']--;
                    }
                    start++;
                }
                int wL = i - start + 1;
                    
                    if(minLength>wL)
                    {
                        minLength = wL;
                        starting_index = start;
                        
                    }
            }
        }
        if(starting_index==-1)
        {
            return "-1";
        }
        
         return s.substr(starting_index,minLength);
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends