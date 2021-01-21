// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

int kthSmallest(int *, int, int, int);

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];

        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];

        int k;
        cin>>k;
        cout<<kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}// } Driver Code Ends


//User function template for C++

// arr : given array
// l : starting index of the array i.e 0
// r : ending index of the array i.e size-1
// k : find kth smallest element and return using this function
int partition2(int a[], int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

int rand_qs(int arr[],int l, int r,int k)
{
        if(k>0&&k<=r-l+1){
    int s=l+rand()%(r-l+1);
    swap(arr[l],arr[s]); int m;
    m = partition2(arr,l,r);
    if(m-l == k-1)
    {
        return arr[m];
    }
    if(k-1<m-l)
   return rand_qs(arr,l,m-1,k);
   else if(k-1>m-l)
   returnA rand_qs(arr,m+1,r,k-m+l-1);}


}

int kthSmallest(int arr[], int l, int r, int k) {
    int x=rand_qs(arr,l,r,k);
    return x;
}
