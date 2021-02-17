#include <iostream>
#include <vector>
using namespace std;

void cal(string s){
    int n=s.size();
    vector<vector<bool>>t(n,vector<bool>(n));int max=1;int st=0;
    for(int i=0;i<n;i++)
        {t[i][i]=1;}
    for(int i=0;i<n-1;i++)
    {
        if(s[i]==s[i+1])
        {t[i][i+1]=1;if(max<2)
                    {
                        max=2;st=i;
                    }}
    }
    for(int k=3;k<n+1;k++)
    {
        for(int i=0;i<n-k+1;i++)
        {
            int j=i+k-1;
            if(t[i+1][j-1]&&s[i]==s[j])
                {
                    t[i][j]=1;
                    if(k>max)
                    {
                        max=k;st=i;
                    }
                }

        }
    }string res="";
    for(int i=st;i<st+max;i++)
    {
        res+=s[i];
    }
    cout<<res<<endl;
}

int main() {
	int t=0;
	cin>>t;
	while(t--){
	    string s="";
	    cin>>s;
	    cal(s);
	}
	return 0;
}
