// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
string reverseWords(string s);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout<<reverseWords(s)<<endl;
    }
}// } Driver Code Ends


string reverseWords(string s)
{
    int n=s.length();
    string y="";string x="";
    for(int i=0;i<n;i++)
    {

        if(s[i]=='.')
        {
            y="."+x+y;
            x="";
        }
        else if(i==n-1)
        {
            x+=s[i];
            y=x+y;

        }
        else
        x+=s[i];


    }
    return y;
}
