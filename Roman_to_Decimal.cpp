// { Driver Code Starts
// Initial template for C++

// Program to convert Roman Numerals to Numbers
#include <bits/stdc++.h>
using namespace std;

// Returns decimal value of roman numaral
int romanToDecimal(string &);

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << romanToDecimal(s) << endl;
    }
}// } Driver Code Ends


// User fuunction teemplate for C++

// str given roman number string
// Returns decimal value of roman numaral
int tod(char c)
{
    int x=0;
     if(c=='I')
     x=1;
     else if(c=='V')
     x=5;
     else if(c=='X')
     x=10;
     else if(c=='L')
     x=50;
     else if(c=='C')
     x=100;
     else if(c=='D')
     x=500;
     else if(c=='M')
     x=1000;
     
    return x;
}
int romanToDecimal(string &str) {int res=tod(str[str.size()-1]);
    for(int i=str.size()-2;i>=0;i--){
        if(tod(str[i])>=tod(str[i+1]))
            res+=tod(str[i]);
        else
        {res-=tod(str[i]);/*cout<<str[1]<<" ";*/}
    }
    return res;
    
}