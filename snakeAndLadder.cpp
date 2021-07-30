// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minThrow(int N, int arr[]){
        vector<int>moves(30,-1);
        
        for(int i=0;i<N;i++)
        {
            moves[arr[2*i]-1]=arr[(2*i)+1]-1;
        }
        
        vector<bool>vis(30,false);
        
        vector<int>num(30,INT_MAX);
        num[0]=0;vis[0]=1;
        
        queue<int>q;
        q.push(0);
        while(!q.empty())
        {
            int t = q.front();
            
            q.pop();
            
            if(t==29)
            return num[29];
            
            for(int i=1;i<=6;i++)
            {
                
                if(t+i<30&&!vis[t+i])
                {
                    vis[t+i]=1;
                    num[t+i]=num[t]+1;
                    if(moves[t+i]!=-1)
                    {
                        q.push(moves[t+i]);
                        if(num[moves[t+i]]>num[t+i])
                            num[moves[t+i]]=num[t+i];
                        vis[moves[t+i]]=1;
                    }
                    else
                    q.push(t+i);
                }
            }
        }
        
        // if(num[29]!=-1)
        return num[29];
        
        
    }
    
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}  // } Driver Code Ends