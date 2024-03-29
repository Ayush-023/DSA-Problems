// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};


int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int q;
       cin>>q;
        _stack *a = new _stack();
       while(q--){

       int qt;
       cin>>qt;

       if(qt==1)
       {
           //push
           int att;
           cin>>att;
           a->push(att);
       }
       else if(qt==2)
       {
           //pop
           cout<<a->pop()<<" ";
       }
       else if(qt==3)
       {
           //getMin
           cout<<a->getMin()<<" ";
       }
       }
       cout<<endl;
   }

}


// } Driver Code Ends


/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

/*returns min element from stack*/
int _stack :: getMin()
{
    if(!s.empty())
    return minEle;
    else
    return -1;
}

/*returns poped element from stack*/
int _stack ::pop()
{
   if(!s.empty())
   {
       int x=s.top();
      if(x<minEle)
      {
          x=minEle;
          minEle=2*minEle-s.top();
          
          s.pop();
        //   if(s.empty())
        //   return -1;
        //   else
          return x;
      }
      else
      {s.pop();
      return x;}
   }
   else
   {
       return -1;
   }
}

/*push element x into the stack*/
void _stack::push(int x)
{   
    if(minEle==0||s.empty())
    {
        s.push(x);
        minEle=x;
    }

    else if(x<minEle)
    {
        
        s.push(2*x-minEle);
        minEle=x;
    }
    else
   s.push(x);
}