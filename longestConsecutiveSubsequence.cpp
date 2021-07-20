// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      map<int,bool>map;
      
      for(int i=0;i<N;i++)
      {
          map[arr[i]]=true;
      }
      int longest = 1,current = 0;bool prevFlag = false;auto prev = map.begin();
      for(auto it=++map.begin();it!=map.end();it++)
      {
          if(it->second&&prev->first+1==it->first)
          {
                //   cout<<it->first<<" :: ";
                if(!prevFlag)
                  {prevFlag = true;current+=2;}
                 else
                  current++;
                  
          }
          else
          {
              prevFlag = false;
              current = 0;
          }
          longest = max(longest,current);
          prev = it;
      }
      return longest;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends