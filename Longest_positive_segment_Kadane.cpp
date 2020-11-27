#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find subarray with maximum sum
// arr: input array
// n: size of array
int maxSubarraySum(int arr[], int n){
int sum=arr[0],moving=0;
for(int i=0;i<n;i++)
{
 moving+=arr[i];
 if(moving>sum)
 {
     sum=moving;
 }
 if(moving<0&&arr[i+1]>0){
     moving=0;
 }
}
    return sum;
}

// { Driver Code Starts.

int main()
{
    int t,n;

    cin>>t; //input testcases
    while(t--) //while testcases exist
    {

        cin>>n; //input size of array

        int a[n];

        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array

        cout << maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends
