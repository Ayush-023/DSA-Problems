// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
public:

    int binarySearch(int arr[],int l,int r, int k)
    {
        if(l>r)
        return -1;
        
        int mid = l + (r-l)/2;
        
        if(arr[mid]==k)
        return mid;
        
        else if(arr[mid]>k)

           return binarySearch(arr,l,mid-1,k);
        else
           return binarySearch(arr,mid+1,r,k);
    }
    
    int binarysearch(int arr[], int n, int k){
        
        int l=0,r=n-1;
        
       return binarySearch(arr,l,r,k);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int N;
        cin>>N;
        int arr[N];
        for(int i=0;i<N;i++)
            cin>>arr[i];
        int key;
        cin>>key;
        Solution ob;
        int found = ob.binarysearch(arr,N,key);
        cout<<found<<endl;
    }
}

  // } Driver Code Ends