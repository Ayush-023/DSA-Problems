// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int maxLen(int A[], int n);

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++)
            cin >> A[i];
        cout << maxLen(A, N) << endl;
    }
}
// } Driver Code Ends


/*You are required to complete this function*/

int maxLen(int a[], int n)
{
    unordered_map<int,int>umap;
    
    long sum = 0; int maxLength = 0;
    
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
        
        if(sum==0)
        {
            maxLength = max(maxLength,i+1);  
        }
        
        if(umap.find(sum)==umap.end())
        {
            umap[sum]=i;
        }
        else
        {
            maxLength = max(maxLength,i-umap[sum]);
        }
    }
    return maxLength;
}
