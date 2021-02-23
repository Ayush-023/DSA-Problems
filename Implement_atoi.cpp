// { Driver Code Starts
 #include <bits/stdc++.h>
using namespace std;

int atoi(string str);
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		cout<<atoi(s)<<endl;
	}
}// } Driver Code Ends


/*You are required to complete this method */
int atoi(string str)
{
    // int res=0;
    for(int i=str.size()-1;i>=0;i--)
    {
       
        if(str[i]<='9')
        continue;
        else
        return -1;
    }
    
    stringstream ss(str);
    int x=0;
    ss>>x;
    return x;
}