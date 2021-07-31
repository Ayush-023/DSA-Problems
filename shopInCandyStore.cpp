// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int n, int k)
    {
        sort(candies,candies+n);
        
        int minM=0,maxM=0;
        
        int i=0,j=n-1;
        while(i<=j)
        {
            minM+=candies[i];
            j-=k;
            i++;
        }
        vector<int>res(2);
        res[0]=minM;
        i=0;j=n-1;
        while(i<=j)
        {
            maxM+=candies[j];
            j--;
            i+=k;
        }
        res[1]=maxM;
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}  // } Driver Code Ends