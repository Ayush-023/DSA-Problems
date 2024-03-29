// { Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

 // } Driver Code Ends
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int l, int h)
    {
        if(l>=h)
        return;
        
        int x = l+rand()%(h-l);
        
        swap(arr[x],arr[l]);
        
        int m = partition(arr,l,h);
        
        quickSort(arr,m+1,h);
        quickSort(arr,l,m-1);
        
    }
    
    int partition (int arr[], int low, int high)
    {
       int j=low,pivot=arr[low];
       
       for(int i=low+1;i<=high;i++)
       {
           if(arr[i]<=pivot)
           {
               j++;
               swap(arr[i],arr[j]);
               
           }
       }
       swap(arr[low],arr[j]);
       
       return j;
    }
};


// { Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}  // } Driver Code Ends