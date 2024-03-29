// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    void dfs(vector<vector<int>>&adj,string&s,int x,vector<bool>&vis)
    {
        vis[x]=true;
        
        for(int j:adj[x])
        {
            if(!vis[j])
            {
                dfs(adj,s,j,vis);
            }
        }
        char c = (char)((int)'a'+x);
        // cout<<x<<"|";
        s.push_back(c);
    }
    
    void topSort(vector<vector<int>>&adj,string&s)
    {
        vector<bool>vis(adj.size(),false);
        for(int i=0;i<adj.size();i++)
        {
            if(!vis[i])
            {
                dfs(adj,s,i,vis);
            }
        }
        reverse(s.begin(),s.end());
    }
    
    string findOrder(string dict[], int n, int K) {
        vector<vector<int>>adj(K);
        
        for(int i=0;i<n-1;i++)
        {
            string s1=dict[i],s2=dict[i+1];
            for(int j=0;j<min(s1.length(),s2.length());j++)
            {
                if(s1[j]!=s2[j])
                {
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
            }
        }
        
        string s;
        topSort(adj,s);
        // cout<<s<<endl;
        return s;
    }
};

// { Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends