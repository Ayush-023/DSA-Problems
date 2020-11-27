// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



void merge(int arr1[], int arr2[], int n, int m)
{
    int gap=(n+m)/2;
    for(;gap>0;gap/=2)
    {
        for(int i=gap;i<n+m;i++)
        {
            int temp=0;
            if(i>=n){
                temp=arr2[i-n];
            }
            else
            {
                temp=arr1[i];
            }
            int j;
           for(j=i;j>=gap;j-=gap)
           {
               if(j-gap>=n&&arr2[j-gap-n]>temp){
                   arr2[j-n]=arr2[(j-gap)-n];
               }
               else if(j-gap<n&&j>=n&&arr1[j-gap]>temp){
                   arr2[j-n]=arr1[j-gap];
               }
               else if(j-gap<n&&j<n&&arr1[j-gap]>temp)
               {
                   arr1[j]=arr1[j-gap];
               }
               else
               {
                   break;
               }
           }

        //   cerr<<j<<' : ';
           if(j>=n){
               //cout<<temp<<" : "<<arr2[j-n]<<" ; ";
                arr2[j-n]=temp;

            }
            else
            {
                //cout<<temp<<" : "<<arr1[j]<<" ; ";
                arr1[j]=temp;

            }
        }
    }
}


// { Driver Code Starts.

int main()
{

	int T;
	cin >> T;

	while(T--){
	    int n, m;
	    cin >> n >> m;

	    int arr1[n], arr2[m];

	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }

	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }

	    merge(arr1, arr2, n, m);

        for (int i = 0; i < n; i++)
            printf("%d ", arr1[i]);


	    for (int i = 0; i < m; i++)
		    printf("%d ", arr2[i]);

	    cout<<endl;
	}

	return 0;
}
  // } Driver Code Ends
