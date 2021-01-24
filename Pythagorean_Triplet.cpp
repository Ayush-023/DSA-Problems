// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends


//User function template for C++
class Solution{
public:
	// Function to check if the
	// Pythagorean triplet exists or not
	bool checkTriplet(int arr[], int n) {
	    for(int i=0;i<n;i++)
	    {
	        arr[i]*=arr[i];
	    }

      int c= countTriplet(arr,n);
      return c;
	}
	int countTriplet(int arr[], int n)
	{
	    int count=0,sum=0,start=0,end=0;
	    sort(arr,arr+n);
	    for(int i= 2; i<n;i++)
	    {
	        if(count>0)
	            break;
	        sum=arr[i];start=0;end=i-1;
	        while(start<end)
	        {
	            if(count>0)
	            break;
	            if(arr[start]+arr[end]<sum)
	            {
	                start++;
	            }
	            else if(arr[start]+arr[end]>sum)
	            {
	                end--;
	            }
	            else
	            {count++;start++;}
	        }
	    }
	    return count;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.checkTriplet(arr, n);
        if (ans) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
  // } Driver Code Ends
