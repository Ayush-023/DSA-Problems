// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function template for C++

class Solution{
public:
    void reverseInGroups(vector<long long>& arr, int n, int k){
        vector<long long> revers;int c=0;
        if(k>n)
        {
            k=n;
        } int i=0;

        for( i=0;i<n;i++)
        {
            if(i%k==0)
            {
                c=i;
            }
            if(i%k<k/2)
            {
                if(c+k-((i+1)%k)>=n)
                {
                    k=n-i;
                    break;
                }
                else
                swap(arr[i],arr[c+k-((i+1)%k)]);
            }
        }int j=i;
        for(;j<n;j++)
        {
            revers.push_back(arr[j]);
        }
        reverse(revers.begin(),revers.end());j=0;
        for(;i<n;i++)
        {
            arr[i]=revers[j];
            j++;
        }
        }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> arr;
        int k;
        cin >> k;

        for(long long i = 0; i<n; i++)
        {
            long long x;
            cin >> x;
            arr.push_back(x);
        }
        Solution ob;
        ob.reverseInGroups(arr, n, k);

        for(long long i = 0; i<n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

  // } Driver Code Ends
