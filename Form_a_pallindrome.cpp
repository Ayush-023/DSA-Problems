#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

void cal(string s){
    vector<vector<int>>t(s.size(),vector<int>(s.size()));
    for(int i=0;i<s.size();i++){
       for(int j=0;j<s.size();j++){
           t[i][j]=0;
       }
    }
    for(int i=1;i<s.size();i++)
    {
        for(int j=0,h=i;h<s.size();j++,h++)
        {
            t[j][h]=(s[j]==s[h])?(t[j+1][h-1]):(min(t[j+1][h],t[j][h-1])+1);
        }
    }
    cout<<t[0][s.size()-1]<<endl;
}

int main() {
	int t=0;
	cin>>t;
	while(t--){string s="";
	    cin>>s;
	    cal(s);
	}
	return 0;
}