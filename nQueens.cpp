// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isValidState(const vector<int>&state,int n)
    {
        return (state.size()==n);
    }
    
    vector<int>candidates(const vector<int>&state,int n)
    {
        if(state.size()==0)
        {
            vector<int>v(n);
            for(int i=0;i<n;i++)
            {
                v[i]=i+1;
            }
            return v;
        }
        
        int position = state.size();
        vector<int>c(n);
        for(int i=0;i<n;i++)
            {
                c[i]=i+1;
            }
        for(int i=0;i<state.size();i++)
        {
            int row = i, col = state[i],dist=position-row;
            
            for(int i=0;i<c.size();i++)
            {  
                if(c[i]==col)
                 {
                     c.erase(c.begin()+i);
                     break;
                 }
            }
            for(int i=0;i<c.size();i++)
            {  
                if(c[i]==col+dist)
                 {
                     c.erase(c.begin()+i);
                     break;
                 }
            }
            for(int i=0;i<c.size();i++)
            {  
                if(c[i]==col-dist)
                 {
                     c.erase(c.begin()+i);
                     break;
                 }
            }
        }
        return c;
    }
    
    void search(vector<vector<int>>&solution,vector<int>&state,int n)
    {
        if(isValidState(state,n))
        {
            solution.push_back(state);
            return;
        }
        
        vector<int>c = candidates(state,n);
        
        for(int i=0;i<c.size();i++)
        {
            state.push_back(c[i]);
            search(solution,state,n);
            state.pop_back();
        }
    }

    vector<vector<int>> nQueen(int n) {
        vector<vector<int>>solution;
        vector<int>state;
        
        search(solution,state,n);
        sort(solution.begin(),solution.end());
        
        return solution;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends