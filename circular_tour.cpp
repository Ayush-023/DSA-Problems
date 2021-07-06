// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


 // } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    // int tour(petrolPump p[],int n)
    // {
    // //   vector<bool>vis(n);
    //   int sum=0,start=0,end=0,i=0;
    //     int j=0;
    //   while(true)
    //   {
    //       //cout<<end<<" :: "<<start<<"  || ";
    //       if(sum>=0&&(end+1)%n==start)
    //       {
    //           break;
    //       }
    //       else if(j==n+start)
    //       {
    //           start=-1;
    //           break;
    //       }
           
    //       if(sum<0)
    //       {
    //           start=i%n;
    //           end=i%n;
    //           sum=p[i].petrol-p[i].distance;//j=0;
    //       }
    //       else
    //       {
    //           sum+=p[i].petrol-p[i].distance;
    //           end++;
    //           end%=n;
    //       }
           
    //       i++;i%=n;j++;
           
    //   }
       
    // return start;
       
    // }
    int tour(petrolPump arr[], int n)
    {
    	
    	int start = 0;
    	int end = 1;
    
    	int curr_petrol = arr[start].petrol - arr[start].distance;
    
    	while (end != start || curr_petrol < 0)
    	{
    		
    		while (curr_petrol < 0 && start != end)
    		{
    			
    			curr_petrol -= arr[start].petrol - arr[start].distance;
    			start = (start + 1) % n;
    
    			
    			if (start == 0)
    			return -1;
    		}
    
    		
    		curr_petrol += arr[end].petrol - arr[end].distance;
    
    		end = (end + 1) % n;
    	}
    
    	return start;
    }
};



// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}
  // } Driver Code Ends