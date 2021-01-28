// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends

class Solution{
public:
	// The main function that returns the arrangement with the largest value as
	// string.
	// The function accepts a vector of strings
	static bool mcompare(string x,string y)
	{
	    string xy=x+y;
	    string yx= y+x;
	    return(xy.compare(yx)>0?1:0);
	}

	string printLargest(vector<string> &arr) {
	   sort(arr.begin(),arr.end(),mcompare);
        string x = "";
        for(int i=0;i<arr.size();i++)
        {
            x+=arr[i];
        }
    return x;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<string> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printLargest(arr);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
