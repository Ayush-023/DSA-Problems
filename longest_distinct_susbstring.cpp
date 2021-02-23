#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void cal(string s){
    
    int ma=0,c=0;
    for(int i=0;i<s.size();i++)
    {
        vector<bool>vis(26);
        for(int j=i;j<s.size();j++)
        {
            if(vis[s[j]-'a']==true)
            {
                break;
            }
            else
            {
                vis[s[j]-'a']=true;
                ma=max(ma,j-i+1);
            }
        }
        
    }
    cout<<ma<<endl;
    
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