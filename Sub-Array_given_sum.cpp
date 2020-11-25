
#include <iostream>
#include <vector>
using namespace std;

pair<int,int> func(vector<int>arr, int s)
{
    int sum=arr[0]; pair<int,int> ret = {-1,-1};int j=0;
    for(int i=1;i<arr.size();i++)
    {
            sum+=arr[i];
            if(sum>s)
            {
                while(sum>s)
                {
                    sum-=arr[j];
                    j++;
                }
            }
            if(sum == s)
            {
                ret = make_pair(j+1,i+1);
                break;
            }

    }
    return ret;
}

int main() {
	int t=0;
	cin>>t;
	vector<pair<int,int>> result(0);
// 	int sum=0,n=0;
	while(t>0)
	{
	    vector<int> array;
	    int sum=0,n=0;
	    cin>>n>>sum;
	    array.resize(n);
	    for(int i=0; i<n;i++){
	        cin>>array[i];
	    }
	    result.push_back(func(array,sum));
	    t--;
	 }
	 for(int i=0;i<result.size();i++)
	 {
	     if(result[i].first==-1&&result[i].second==-1)
	     {
	         cout<<-1<<endl;
	     }
	     else
	     cout<<result[i].first<<" "<<result[i].second<<endl;
	 }
	return 0;
}
