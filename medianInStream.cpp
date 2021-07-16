// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    priority_queue <double, vector<double>, greater<double> > r;
    priority_queue <double> l;
    double m;
    public:
    Solution()
    {
        m = 0;
    }
    //Function to insert heap.
    void insertHeap(int &x)
    {
        balanceHeaps();
        int left = l.size();
        int right = r.size();
        
        if(left<right)
        {
            if(x<m)
            {
                l.push(x);
                m = (l.top()+r.top())/2;
            }
            else
            {
                double top = r.top();
                r.pop();
                r.push(x);
                l.push(top);
                m = (l.top()+r.top())/2;
            }
        }
        else if(left>right)
        {
            if(x<m)
            {
                double top = l.top(); l.pop();
                r.push(top);
                l.push(x);
                m = (l.top()+r.top())/2;
            }
            else
            {
                r.push(x);
                m = (l.top()+r.top())/2;
            }
        }
        else
        {
           if(x<m)
           {
               l.push(x);
               m = l.top();
           }
           else
           {
               r.push(x);
               m = r.top();
           }
        }
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        return;
    }
    
    //Function to return Median.
    double getMedian()
    {
        return m;
    }
};


// { Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}  // } Driver Code Ends