// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends




// Function to count number of pairs such that x^y is greater than y^x
// X[], Y[]: input arrau
// m, n: size of arrays X[] and Y[] respectively
long long countPairs(int X[], int Y[], int m, int n)
{
    long long count=0;
   sort(Y,Y+n);
   sort(X,X+m);
   for(int i=0;i<m;i++)
   {
       if(X[i]==0||X[i]==1){
           continue;
       }
       int key=X[i];int *index=upper_bound(Y,Y+n,key);int mid=(Y+n)-index;
    //   int start=0,end=n;int mid=0;bool t=false;
    //   while(start<end){
    //       mid=start + (end-start)/2;
    //       if(Y[mid]==key){mid++;t=true;
    //           break;
    //       }
    //       else if(Y[mid]<key){
    //           start=mid+1; //cout<<"|mid: "<<mid<<"| "<<key<<" : \n";
    //           if(start==end){
    //               mid++;
    //           }
    //       }
    //       else{
    //           end=mid-1; //cout<<"|mid: "<<mid<<"| "<<key<<" : \n";
    //       }
    //   }
    //   if(!t)
    //   mid++;
    //   cout<<"|mid: "<<mid<<"| "<<key<<" : ";
       count+=mid;
   }

   int j=0,nn;

   while(Y[j]<3){
    if(Y[j]==0){
        count+=m; nn=0;
        while(X[nn<1]){
            if(X[nn]==0)
            count--;
            nn++;
        }
    }nn=0;
    if(Y[j]==2){
       while(X[nn]<4){
           if(X[nn]==3){
              count++;
           }nn++;
       }
   }
   if(Y[j]==1){
   count+=m;nn=0;
   while(X[nn]<2){
           if(X[nn]==1){
              count--;
           }
           if(X[nn]==0){
              count--;
           }nn++;
       }
   }
    j++;
   }

   j=0;
   while(X[j]<3){
   if(X[j]==2)
   {
       nn=0;
       while(Y[nn]<5){
           if(Y[nn]==3){
              count--;
           }
           if(Y[nn]==4){
               count--;
           }nn++;
       }
   }
   j++;
   }

   return count;
}



// { Driver Code Starts.
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int M,N;
		cin>>M>>N;
		int i,a[M],b[N];
		for(i=0;i<M;i++)
		{
			cin>>a[i];
		}
		for(i=0;i<N;i++)
		{
			cin>>b[i];
		}
		cout<<countPairs(a, b, M, N)<<endl;
	}
}  // } Driver Code Ends
