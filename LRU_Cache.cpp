#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
    private:
        int ca;
        int key;
        unordered_map<int,list<pair<int,int>>::iterator>mp;
        int count;
        list<pair<int,int>>q;
    public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        ca=cap;
        count=0;
    }
    
    //Function to return value corresponding to the key.
    int get(int key)
    {
        if(mp.find(key)!=mp.end())
        {
            auto x= mp.find(key)->second;
           int y=(*x).second;
            q.erase(mp[key]);
            q.push_back({key,y});
            mp[key]=--q.end();
            return y;
        }
        else
        return -1;
    }
    
    //Function for storing key-value pair.
     void set(int key, int value)
    {
        if(mp.find(key)==mp.end())
        {
            if(count==ca)
                {
                  pair<int,int> rem=q.front();q.pop_front();
                  mp.erase(mp.find(rem.first));
                  count--;
                }
        
             q.push_back({key,value});
                mp[key]=--q.end();
                count++;
        }
        else
        {
            q.erase(mp[key]);
            q.push_back({key,value});
            mp[key]=--q.end();
        }
        
    }
};



// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends