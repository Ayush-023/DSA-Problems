// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char>s;
        for(int i=0;i<x.length();i++)
        {
            char ss=x[i];
            if(x[i]=='{'||x[i]=='('||x[i]=='[')
                s.push(x[i]);
            else
            {
                if(s.empty())
                {
                    return false;
                }
                char last=s.top();
                // cout<<ss<<" :: ";
                s.pop();
                if(ss=='}'&&last=='{')
                {   
                    continue;
                }
                else if(ss==']'&&last=='[')
                {
                    continue;
                }
                else if(ss==')'&&last=='(')
                {
                    continue;
                }
                else
                return false;
            }
        }
        if(s.empty())
            return true;
            
        return false;
    }

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends