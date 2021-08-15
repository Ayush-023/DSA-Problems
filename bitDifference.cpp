// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // Function to count set bits
    int countSetBits(unsigned int n)
    {
        //We use a counter variable
      unsigned int count = 0;
      while(n)
      {
        //AND operation of n and 1 gives us the rightmost bit. 
        //counter variable is increased if we get 1 as the rightmost bit.
        count += n & 1;
        
        //Right Shift n by 1 to remove the rightmost bit.
        n >>= 1;
        
      }
      return count;
    }
    
    
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b){
        
        int ans = 0;
        //XOR operation gives set bits only when there are dissimilar bits.
        //We store the value of XOR operation of a and b.
        ans = a^b;
        
        //returning the number of set bits in resultant.
        return countSetBits(ans);
        
    }
};

// { Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin>>t;// input the testcases
    while(t--) //while testcases exist
    {
        int a,b;
        cin>>a>>b; //input a and b

        Solution ob;
        cout<<ob.countBitsFlip(a, b)<<endl;
    }
    return 0;
}  // } Driver Code Ends