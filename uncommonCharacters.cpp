// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
        string UncommonChars(string A, string B)
        {
           vector<int>hash(26,-3);
           
           for(int i=0;i<A.length();i++)
           {
               hash[A[i]-'a']=1;
           }
           
           for(int i=0;i<B.length();i++)
           {
               if(hash[B[i]-'a']==1||hash[B[i]-'a']==-1)
               {
                   hash[B[i]-'a']=-1;
               }
              else
              {
                  hash[B[i]-'a']=2;
              }
           }
           string result;
           
            for(int i=0;i<26;i++)
            {
                if(hash[i]==1||hash[i]==2)
                {
                    result+=char(int('a')+i);
                }
            }
            if(result.empty())
            {
                return "-1";
            }
           return result;
        }
};



// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;
        Solution ob;
        cout<<ob.UncommonChars(A, B);
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends