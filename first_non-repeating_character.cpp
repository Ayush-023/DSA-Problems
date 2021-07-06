// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string a){
		    int non=0;string ans;ans.push_back(a[0]);vector<int>vis(26,0);
		   // cout<<ans<<" || ";
		    vis[a[0]-'a']++;
		    for(int i=1;i<a.length();i++)
		    {
		        vis[a[i]-'a']++;
		        
		        if(vis[a[non]-'a']>1)
		        {
		            while(vis[a[non]-'a']>1&&non<i)
		            {
		                non++;
		            }
		            if(vis[a[non]-'a']>1)
		            {
		                ans.push_back('#');
		            }
		            else{
		                ans.push_back(a[non]);
		            }
		        }
		        else
		        {
		            ans.push_back(a[non]);
		        }
		    }
		    return ans;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends