// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


//User function template for C++
class Solution{
public:

	int countTriplet(int arr[], int n)
	{
	    int count=0,sum=0,start=0,end=0;
	    sort(arr,arr+n);
	    for(int i= 2; i<n;i++)
	    {
	        sum=arr[i];start=0;end=i-1;
	        while(start<end)
	        {
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


int main()
{

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
        	cin >> arr[i];

        Solution ob;
        cout << ob.countTriplet(arr, n) << "\n";

    }

    return 0;
}  // }
