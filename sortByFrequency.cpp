#include <bits/stdc++.h>

using namespace std;

bool comp(pair<int,int>a,pair<int,int>b)
{
    if(a.second!=b.second)
    {
        return(a.second>b.second);
    }
    
    return(a.first<b.first);
}

void sort(map<int,int>map)
{
    vector<pair<int,int>>result;
    
    for(auto it=map.begin();it!=map.end();it++)
    {
        result.push_back({it->first,it->second});
    }
    
    sort(result.begin(),result.end(),comp);
    
    for(int i=0;i<result.size();i++)
    {
        int count = result[i].second;
        int value = result[i].first;
        
        while(count--)
        {
            cout<<value<<" ";
        }
    }
    cout<<"\n";
}

int main() {
	int t=0;
	cin>>t;
	while(t--)
	{
	    int n;cin>>n;
	    map<int,int>map;
	    
	    for(int i=0;i<n;i++)
	    {
	        int input;
	        cin>>input;
	        map[input]+=1;
	    }
	    
	    sort(map);
	}
	return 0;
}