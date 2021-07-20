// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        vector<vector<int>>res;
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int left,right;
        for(int i=0;i<n-3;i++)
        {
            for(int j=i+1;j<n-2;j++)
            {
                left = j+1;right = n-1;
                while(left<right)
                {
                    int sum = arr[i]+arr[j]+arr[left]+arr[right];
                    if(sum<k)
                    {
                        left++;
                    }
                    else if(sum>k)
                    {
                        right--;
                    }
                    else
                    {
                        vector<int>r{arr[i],arr[j],arr[left],arr[right]};
                        res.push_back(r);
                        left++;right--;
                    }
                }
            }
        }
        
        set<vector<int> > s( res.begin(), res.end() );
        res.assign( s.begin(), s.end() );
        
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends