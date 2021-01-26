#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

void diff(vector<int>a,int n,int m)
{
    sort(a.begin(),a.end());
    int d=10000000;
    for(int i=0;i<=n-m;i++)
    {
        d=min((a[i+m-1]-a[i]),d);
    }
    cout<<d<<endl;
}

int main() {
	int t=0,n=0,m=0;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    vector<int>a(n);
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    cin>>m;
	    diff(a,n,m);
	}
	return 0;
}
