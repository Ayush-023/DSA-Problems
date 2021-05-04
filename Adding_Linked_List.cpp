// { Driver Code Starts
// driver

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
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
   struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        first=reverseList(first);
        second=reverseList(second);
        Node*cur=0;int carry=0;
        cur=new Node(0);Node*head=cur;
        while(true)
        {
            if(!first&&!second)
            {
                cur->data+=carry;
                cur->next=0;
                break;
            }
            int x =0;
            if(first&&second)
            { x=first->data+second->data+carry;first=first->next;second=second->next;}
             
            else if(first==0)
            {
                x=second->data+carry;
                second=second->next;
            }
            else
            {
                 x=first->data+carry;
                 first=first->next;
            }
            
            if(x/10)
            {
                carry=x/10;
                x=x%10;
            }
            else
            carry=0;
         
         cur->data=x;

         cur->next=new Node(0);
         cur=cur->next;
         
        }
        head=reverseList(head);
        if(!head->data)
        return head->next;
        
        return head;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends