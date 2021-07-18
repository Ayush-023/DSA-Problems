// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    vector<int> kthLargest(int k, int arr[], int n) {
        vector<int>result;
        priority_queue <int, vector<int>, greater<int>> min;
        
        for(int i=0;i<n;i++)
        {
            if(min.size()<k)
            {
                min.push(arr[i]);
            }
            else
            {
                if(arr[i]>min.top())
                {
                    min.pop();
                    min.push(arr[i]);
                }
            }
                
                if(min.size()<k)
                {
                    result.push_back(-1);// { Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    cout<<endl;
}

 // } Driver Code Ends
/*Linked list Node structure

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/ 

struct compare{
    bool operator()(Node*a,Node*b)
    {
        return (a->data > b->data);
    }
};

class Solution{
  public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int k)
    {
        priority_queue<Node*,vector<Node*>,compare> pq;
        
        for(int i=0;i<k;i++)
        {
            if(arr[i])
            pq.push(arr[i]);
        }
        
        if(pq.empty())
        {
            return NULL;
        }
        
        Node *head = new Node(0);
        Node *temp = head;
        
        while(!pq.empty())
        {
            Node *cur = pq.top();
            pq.pop();
            
            temp->next = cur;
            
            if(cur->next)
            {
                pq.push(cur->next);
            }
            
            temp = temp->next;
        }
        
        return head->next;
    }
};



// { Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int N;
       cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
        }
        Solution obj;
        Node *res = obj.mergeKLists(arr,N);
        printList(res);

   }

    return 0;
}
  // } Driver Code Ends
                }
                else
                {
                    result.push_back(min.top());
                }
            }
       return result;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k,n;
        cin>>k>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> v = ob.kthLargest(k,arr,n);
        for(int i : v)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends