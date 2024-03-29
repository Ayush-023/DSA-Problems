// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    vector<pair<int,int>> allPairs(int A[], int B[], int N, int M, int X)
    {
        unordered_map<int,int>umap;
        vector<pair<int,int>>result;
        
        for(int i=0;i<N;i++)
        {
            umap[A[i]]+=1;
        }
        
        for(int i=0;i<M;i++)
        {
            if(umap.find(X-B[i])==umap.end())
            {
                continue;
                
            }
            else
            {
                if(umap[X-B[i]]!=0)
                {result.push_back({X-B[i],B[i]});umap[X-B[i]]--;}
                
            }
            
        }
        sort(result.begin(),result.end());
        return result;
    }
};


// { Driver Code Starts.
int main() {
	long long t;
	cin >> t;
	
	while(t--){
	    int N, M, X;
	    cin >> N >> M >> X;
        int A[N], B[M];
        
	    for(int i = 0;i<N;i++)
	        cin >> A[i];
	    for(int i = 0;i<M;i++)
	        cin >> B[i];
	        
	   Solution ob;
	   vector<pair<int,int>> vp = ob.allPairs(A, B, N, M, X);
	   int sz = vp.size();
        if(sz==0)
        cout<<-1<<endl;
        else{
            for(int i=0;i<sz;i++){
                if(i==0)
                cout<<vp[i].first<<" "<<vp[i].second;
                else
                cout<<", "<<vp[i].first<<" "<<vp[i].second;
            }
            cout<<endl;
        }
	}
	return 0;
}  // } Driver Code Ends