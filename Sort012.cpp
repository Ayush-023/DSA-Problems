// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
void sort012(int[],int);

int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;


    }
    return 0;
}

// } Driver Code Ends


void sort012(int a[], int n)
{
    int count[3]={0,0,0};
    for(int i=0;i<n;i++)
    {
        count[a[i]]++;
    }
    for(int i=0;i<n;i++)
    {
        if(count[0]!=0)
        {
            a[i]=0;count[0]--;
        }
        else if(count[1]!=0)
        {
            a[i]=1;count[1]--;
        }
        else
        {
            a[i]=2;count[2]--;
        }
    }
}
