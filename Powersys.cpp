#include<cmath>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

float calculate(float t, float v)
{
    float r=0.00;
    r = t/10.00;
    r/=log(112/v);
    return r;
}

int main()
{
    float t=0.00,v=0.00;
    vector<float>res;
    while(cin>>t>>v)
    {
        res.push_back(calculate(t,v));
    }
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
    }
}
