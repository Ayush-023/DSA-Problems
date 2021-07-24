// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    vector<pair<int,int>>v;
	    
	    for(int i=0;i<nums.size();i++)
	    {
	        v.push_back({nums[i],i});
	    }
	    
	    sort(v.begin(),v.end());
	    
	    vector<bool>vis(nums.size(),false);
	    
	    int count=0;
	    
	    for(int i=0;i<nums.size();i++)
	    {
	        if(vis[i]||v[i].second==i)
	        continue;
	        
	        int cycleSize=0, j=i;
	        
	        while(!vis[j])
	        {
	            vis[j]=true;
	            
	            cycleSize++;
	            j = v[j].second;
	        }
	        
	        count+=cycleSize-1;
	    }
	    return count;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends