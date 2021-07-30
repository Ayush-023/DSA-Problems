// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    string chooseandswap(string a){
        vector<int>pos(26,-1);
        
        for(int i=0;i<a.length();i++)
        {
            if(pos[a[i]-'a']==-1)
            pos[a[i]-'a']=i;
        }
        int i,j;
        for(i=0;i<a.length();i++)
        {
            bool flag=false;
            if(pos[a[i]-'a']!=-1)
            {
                for(j=0;j<a[i]-'a';j++)
                {
                    if(pos[j]!=-1)
                    {
                        if(pos[j]>pos[a[i]-'a'])
                        {
                            flag=true;
                            break;
                        }
                    }
                }
                if(flag)
                break;
            }
            
        }
        
        if(i<a.length())
        {
            char c = a[i];
            char r = char('a'+j);
            
            for(int i=0;i<a.length();i++)
            {
                if(a[i]==r)
                a[i]=c;
                else if(a[i]==c)
                a[i]=r;
            }
        }
        
        return a;
    }
    
};


// { Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}
  // } Driver Code Ends