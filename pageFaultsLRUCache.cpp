// { Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        list<int>q;
        int count=0;
        
        for(int i=0;i<N;i++)
        {
            int t=1;
            if(q.size()!=0)
            {
                
                for(auto it = q.begin();it!=q.end();it++)
                {
                    if(*it==pages[i])
                    {
                        q.erase(it);
                        t=0;
                        q.push_back(pages[i]);
                        break;
                    }
                }
                
                if(t==1)
                {
                //   cout<<q.size()<<" :: ";
                    count++;
                    if(q.size()>=C)
                        q.pop_front();
                    
                    q.push_back(pages[i]);
                }
            }
            
            else
            {
                q.push_back(pages[i]);
                count++;
            }
            
        }
        return count;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    }
    return 0;
}  // } Driver Code Ends