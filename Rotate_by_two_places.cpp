// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


/*  Function to check if str1 can be formed from
*   str2 after rotation by 2 places
*/
bool isRotated(string str1, string str2)
{
    int n=str2.size();
    if(n>1){
    string s2=str2.substr(0,2);
    string s3=str2.substr(2,n-2);
    if(s3+s2==str1)
    return true;
    
    string s4=str2.substr(0,n-2);
    string s5=str2.substr(n-2,2);

    if(s5+s4==str1)
        return true;
    }
    else
    {
        if(str1==str2)
            return true;
    }
    return false;
}


// { Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		cout<<isRotated(s,b)<<endl;
	}
	return 0;
}
  // } Driver Code Ends