// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




 // } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    struct Node* reverseList(struct Node *head)
    {
        Node* prev=NULL,*nex=NULL,*cur=head;
        while(cur!=NULL)
        {
            nex=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nex;
        }
        return prev;
    }
    
    bool compare(Node *first, Node *second)
    {
        while(first&&second)
        {
            if(first->data!=second->data)
            {
                return false;
            }
            else
            {
                first=first->next;
                second=second->next;
            }
        }
        return true;
    }
    
    bool isPalindrome(Node *head)
    {
        if(head!=NULL&&head->next!=NULL)
        {Node*slow=head,*fast=head,*prev_slow=head;
        while(fast!=NULL&&fast->next!=NULL)
        {
            fast=fast->next->next;
            prev_slow=slow;
            slow=slow->next;
        }
        
        if(fast!=0)
        {
            slow=slow->next;
        }
        
        prev_slow->next=0;
        slow=reverseList(slow);
      return  compare(slow,head);}
      return true;
    }
};


// { Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}

  // } Driver Code Ends