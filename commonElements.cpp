// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//Back-end complete function Template for C++

class Solution{
    public:
        vector<int> common_element(vector<int>v1,vector<int>v2)
    {
        unordered_map<int,int>umap,umap1;
        
        for(int i=0;i<v1.size();i++)
        {
            if (umap.find(v1[i]) == umap.end())
            {
                umap[v1[i]]=1;
            }
            else
                umap[v1[i]]++;
        }
        for(int i=0;i<v2.size();i++)
        {
            if (umap1.find(v2[i]) == umap1.end())
            {
                umap1[v2[i]]=1;
            }
            else
                umap1[v2[i]]++;
        }
        vector<int>result;
        
        for(int i=0;i<v2.size();i++)
        {
            if (umap.find(v2[i]) == umap.end())
            {
                continue;
            }
            else
            {
                int count = min(umap[v2[i]],umap1[v2[i]]);
                umap[v2[i]]=0;
                while(count!=0)
                {
                    result.push_back(v2[i]);
                    count--;
                }
            }
        }
        sort(result.begin(),result.end());
        
        return result;
    }
};

// { Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int>v1(n,0);
        for(int i=0;i<n;i++)
        {
            cin>>v1[i];
        }
        int m;
        cin>>m;
        vector<int>v2(m,0);
        for(int i=0;i<m;i++)
        {
            cin>>v2[i];
        }
        Solution ob;
        vector<int>result;
        result=ob.common_element(v1,v2);
        for(auto i:result)
        {
            cout<<i<<" ";
        }
        cout<<endl;
        
    }
}  // } Driver Code Ends