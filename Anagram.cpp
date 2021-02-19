// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


/*  Function to check if two strings are anagram
*   a, b: input string
*/

int c(char x){
    int y=0;
    if(x=='a')
        y=0;
    else if(x=='b')
        y=1;
    else if(x=='c')
        y=2;
    else if(x=='d')
        y=3;
    else if(x=='e')
        y=4;
    else if(x=='f')
        y=5;
    else if(x=='g')
        y=6;
    else if(x=='h')
        y=7;
    else if(x=='i')
        y=8;
    else if(x=='j')
        y=9;
    else if(x=='k')
        y=10;
    else if(x=='l')
        y=11;
    else if(x=='m')
        y=12;
    else if(x=='n')
        y=13;
    else if(x=='o')
        y=14;
    else if(x=='p')
        y=15;
    else if(x=='q')
        y=16;
    else if(x=='r')
        y=17;
    else if(x=='s')
        y=18;
    else if(x=='t')
        y=19;
    else if(x=='u')
        y=20;
    else if(x=='v')
        y=21;
    else if(x=='w')
        y=22;
    else if(x=='x')
        y=23;
    else if(x=='y')
        y=24;
    else if(x=='z')
        y=25;
  
  return y;
        
}

char d(int x){
    char y=0;
    if(x==0)
        y='a';
    else if(x==1)
        y='b';
    else if(x==2)
        y='c';
    else if(x==3)
        y='d';
    else if(x==4)
        y='e';
    else if(x==5)
        y='f';
    else if(x==6)
        y='g';
    else if(x==7)
        y='h';
    else if(x==8)
        y='i';
    else if(x==9)
        y='j';
    else if(x==10)
        y='k';
    else if(x==11)
        y='l';
    else if(x==12)
        y='m';
    else if(x==13)
        y='n';
    else if(x==14)
        y='o';
    else if(x==15)
        y='p';
    else if(x==16)
        y='q';
    else if(x==17)
        y='r';
    else if(x==18)
        y='s';
    else if(x==19)
        y='t';
    else if(x==20)
        y='u';
    else if(x==21)
        y='v';
    else if(x==22)
        y='w';
    else if(x==23)
        y='x';
    else if(x==24)
        y='y';
    else if(x==25)
        y='z';
  
  return y;
        
}

void count_sort(string &s)
{
    int n=s.length();
    
    vector<int>cs(26,0);
    for(auto it:s)
    {
        cs[c(it)]++;
    }
    string res="";
    for(int i=0;i<cs.size();i++)
    {
        while(cs[i]--)
        {
            res+=d(i);
        }
        
    }
    s=res;
}

bool isAnagram(string a, string b){
    
    count_sort(a);
    count_sort(b);
    if(a==b)
        return true;
        else 
        return false;
}


// { Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;

        if(isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}
  // } Driver Code Ends