// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

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

// This function should rotate list counter-clockwise
// by k and return new head (if changed)
class Solution
{
    public:
    Node* rotate(Node* head, int k)
    {
        
         Node*cur=head,*last=0,*nl=0;int n=0;
         while(cur!=nullptr)
         {
             if(cur->next==0)
             {
                 last=cur;
             }
             cur=cur->next;
             
             n++;
         }k=k%n;
         cur=head;
         if(k!=0)
         {
         for(int i=0;i<k;i++)
         {
             if(i==k-1)
             nl=cur;
             
             cur=cur->next;
         }
         last->next=head;
         nl->next=0;
         head=cur;}
        return head; 
    }
};
    


// { Driver Code Starts.

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;
        
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        cin>> k;
        
        Solution ob;
        head = ob.rotate(head,k);
        printList(head);
    }
    return 1;
}
  // } Driver Code Ends