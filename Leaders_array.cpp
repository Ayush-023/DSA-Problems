// { Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



vector<int> leaders(int arr[], int n){
    vector<int>result;int max=arr[n-1];result.push_back(max);
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]>=max)
        {
            max=arr[i];
            result.push_back(arr[i]);
        }
    }
    reverse(result.begin(),result.end());
    return result;
}

// { Driver Code Starts.

int main()
{
   long long t;
   cin >> t;//testcases
   while (t--)
   {
       long long n;
       cin >> n;//total size of array

        int a[n];

        //inserting elements in the array
        for(long long i =0;i<n;i++){
            cin >> a[i];
        }

        //calling leaders() function
        vector<int> v = leaders(a, n);

        //printing elements of the vector
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }

        cout << endl;

   }
}
  // } Driver Code Ends
