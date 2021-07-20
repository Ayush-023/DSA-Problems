// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int findSwapValues(int A[], int n, int B[], int m)
	{
        int sumA = 0,sumB = 0;
        
        for(int i=0;i<n;i++)
            sumA+=A[i];
        
        for(int i=0;i<m;i++)
            sumB+=B[i];
            
        int target = (sumA - sumB)/2;
        // if(target<0)
        //     target*=-1;
            
        if((sumA-sumB)%2)
        {
            return -1;
        }
        
        sort(A,A+n);
        sort(B,B+m);
        
        int a = 0, b = 0;
        // cout<<target<<" :: ";
        while(a<n&&b<m)
        {
            int comp = A[a]-B[b];
            // if(A[a]-B[b]>0)
            // comp = A[a]-B[b];
            // else
            // comp = B[b]-A[a];
            
            if(comp==target)
            {
                return 1;
                break;
            }
            else if(comp<target)
            {
                a++;
            }
            else
            {
                b++;
            }
        }
        return -1;
	}
 

};

// { Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;
    while (t--)
    {
    	int n,m;
        cin>>n>>m;
        int a[n];
        int b[m];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
            cin>>b[i];
        

        Solution ob;
        cout <<  ob.findSwapValues(a, n, b, m);
	    cout << "\n";
	     
    }
    return 0;
}





  // } Driver Code Ends