// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find inversion count in the array

// arr[]: Input Array
// N : Size of the Array arr[]
void  merge(long long arr[],long long left,long long right,long long mid,long long& count)
{
    long long l[mid-left+1],r[right-mid];long long ls=mid-left+1,rs=right-mid,ress=ls+rs;
    for(int i=0;i<ls;i++)
    {
        l[i]=arr[left+i];
    }
    for(int i=0;i<rs;i++)
    {
        r[i]=arr[mid+1+i];
    }
    long long res[ls+rs];int i=0,j=0,x=0;
    while(i<ls&&j<rs)
    {
        if(l[i]<=r[j])
        {
            res[x]=l[i];
            i++;
        }
        else
        {
            count+=ls-i;
            res[x]=r[j];
            j++;
        }
        x++;
    }
    while(i<ls){
        res[x]=l[i];
        i++;x++;
    }
    while(j<rs){
        res[x]=r[j];
        j++;x++;
    }
    for(int m=0;m<ls;m++){
        arr[left+m]=res[m];
    }
    for(int m=0;m<rs;m++){
        arr[mid+m+1]=res[m+ls];
    }


}


void mergeSort(long long arr[],long long left,long long right,long long& count)
{
    if(left>=right)
    {
        return;
    }
    else
    {
    int mid=(left+right-1)/2;
    mergeSort(arr,left,mid,count);
    mergeSort(arr,mid+1,right,count);
    merge(arr,left,right,mid,count);
    }
}

long long int inversionCount(long long arr[], long long N)
{
    long long count=0;
    mergeSort(arr,0,N-1,count);
    return count;
}


// { Driver Code Starts.

int main() {

    long long T;
    // cin >> T;
    T=1;

    while(T--){
        long long N;
        cin >> N;

        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }


        cout << inversionCount(A,N) << endl;
    }

    return 0;
}
