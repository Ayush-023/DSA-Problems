// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends




// function to find the trapped water in between buildings
// arr: input array
// n: size of array
int trappingWater(int arr[], int n){
   int left[n],right[n];
   for(int i=0;i<n;i++)
   {
       left[i]=0;right[i]=0;
   }int max=arr[0];
   for(int i=1;i<n-1;i++)
   {
       left[i]=max;
       if(arr[i]>max)
       {
           max=arr[i];
       }
   }max=arr[n-1];
   for(int i=n-2;i>0;i--)
   {
       right[i]=max;
       if(arr[i]>max)
       {
           max=arr[i];
       }
   }

//   for(int i=1;i<n-1;i++)
//   {
//       int x=i-1,y=i+1;
//       while(x>=0)
//       {
//           if(arr[x]>left[i])
//           left[i]=max(arr[x],arr[i]);
//           x--;
//       }
//       while(y<n)
//       {
//           if(arr[y]>right[i])
//           right[i]=max(arr[y],arr[i]);
//           y++;
//       }
//   }
//   for(int i=1;i<n-1;i++)
//   {
//       cout<<right[i]<<" : "<<left[i]<<endl;
//   }cout<<endl;
   int sum=0;
   for(int i=1;i<n-1;i++)
   {
       if(left[i]>=arr[i]&&right[i]>=arr[i])
      { int x=left[i]<right[i]?left[i]:right[i];

       sum+=x-arr[i];
      }
   }
   return sum;
}

// { Driver Code Starts.

int main(){

    int t;
    //testcases
    cin >> t;

    while(t--){
        int n;

        //size of array
        cin >> n;

        int a[n];

        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];
        }

        //calling trappingWater() function
        cout << trappingWater(a, n) << endl;

    }

    return 0;
}  // } Driver Code Ends
