// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    vector<int> minPartition(int n)
    {
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;
        vector<int>currency{ 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
        
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<10;j++)
            {
                if(i>=currency[j])
                {
                    dp[i]=min(dp[i],1+dp[i-currency[j]]);
                }
            }
        }
        vector<int>bt;
        
        while(n>0)
        {
            for(int j=0;j<10;j++)
            {
                if(n>=currency[j]&&dp[n]==1+dp[n-currency[j]])
                {
                    bt.push_back(currency[j]);
                    n-=currency[j];
                }
            }
        }
        
        vector<int>count(2001,0);
        
        for(int i=0;i<bt.size();i++)
        {
            count[bt[i]]++;
        }
        bt.clear();
        reverse(currency.begin(),currency.end());
        for(int i=0;i<10;i++)
        {
            while(count[currency[i]]--)
            bt.push_back(currency[i]);
        }
        
        return bt;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends