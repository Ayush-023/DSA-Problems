// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int strstr(string ,string);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        string b;
        
        cin>>a;
        cin>>b;
        
        cout<<strstr(a,b)<<endl;
    }
}
// } Driver Code Ends


/* The function should return position where the target string 
   matches the string str
Your are required to complete this method */
int strstr(string s, string x)
{int z=x.length();bool t=false;int res=-1,nn=0;
     for(int i=0;i<s.length();i++)
     {
         if(s[i]==x[0])
         {
             res=i;
             nn=i;nn++;t=true;
             for(int j=1;j<z;j++)
             {
                 if(s[nn]==x[j])
                 {
                     nn++;t=true;
                 }
                 else
                 {
                     t=false;break;
                 }
             }
             if(t)
             {
                 break;
             }
             else
             res=-1;
         }
     }
     return res;
}