// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution{
    public:
    void findNumbers(vector<int>&a, vector<vector<int>>&res, vector<int>&r, int sum, int start)
    {
        if(sum==0)
        {
            res.push_back(r);
            return;
        }
        
        while(start<a.size()&&sum-a[start]>=0)
        {
            r.push_back(a[start]);
            
            findNumbers(a,res,r,sum-a[start],start+1);
            start++;
            
            r.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int> &A, int N, int B){
        sort(A.begin(),A.end());
        vector<vector<int>>res;
        vector<int>r;
        
        findNumbers(A,res,r,B,0);
        set<vector<int>>s;
        for(int i=0;i<res.size();i++)
        {
            s.insert(res[i]);
        }
        vector<vector<int>>f;
        for(auto it = s.begin();it!=s.end();it++)
        {
            f.push_back(*it);
        }
    //   set<vector<int> > s( result.begin(), result.end() );
    //     result.assign( s.begin(), s.end() );
        
        return f;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N, x, B;
        cin>>N;
        vector<int> A;
        for(int i = 0;i < N;i++)
        {
            cin>>x;
            A.push_back(x);
        }
        cin>>B;
        
        Solution ob;
        vector<vector<int>> result;
        result = ob.combinationSum(A, N, B);
        
        if(result.size() == 0)
        cout<<"Empty"<<endl;
        else{
            for(int i = 0;i < result.size(); i++){
                cout<<"(";
                for(int j = 0; j < result[i].size();j++){
                    cout<<result[i][j];
                    if(j < result[i].size() - 1)
                    cout<<" ";
                }
                cout<<")";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends