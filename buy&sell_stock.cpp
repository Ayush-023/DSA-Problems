// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function template for C++

class Solution{
public:
    vector<vector<int> > stockBuySell(vector<int> a, int n){
        vector<pair<int,int>>ma,mi;
        if(a[0]<a[1])
        {
            mi.push_back({a[0],0});
        }
        for(int i=1;i<n-1;i++)
        {
            if(a[i+1]>a[i]&&a[i]<=a[i-1])
            {
                mi.push_back({a[i],i});
            }
            else if(a[i+1]<a[i]&&a[i]>=a[i-1])
            {
                ma.push_back({a[i],i});
            }
        }
        if(a[n-1]>a[n-2])
        {
            ma.push_back({a[n-1],n-1});
        }

            // for(int i=0;i<ma.size();i++)
            // cout<<ma[i].second<<" : ";

        int si=mi.size()<ma.size()?mi.size():ma.size();
        vector<vector<int> >res(si,vector<int>(si));
       int i=0;int k=0;
            for(int j=0;j<si;j++)
            {
                // if(k>=si||i>=si)
                // break;

               if(mi[k].second>ma[i].second)
                {
                    i++;

                }
                if(j>0){
                if(mi[k].second<res[j-1][1])
                {
                    k++;
                }}
                res[j][0]=mi[k].second;
                res[j][1]=ma[i].second;
                i++;k++;
            }

        return res;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A(n);
        for (int i=0; i<n; ++i){
            cin>>A[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.stockBuySell(A, n);
        if(ans.size()==0)
            cout<<"No Profit";
        else{
            for (int i=0; i<ans.size(); ++i){
                cout<<"("<<ans[i][0]<<" "<<ans[i][1]<<") ";
            }
        }cout<<endl;
    }
    return 0;
}

  // } Driver Code Ends
