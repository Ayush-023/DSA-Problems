// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
public:


    // bool isValid(int x,int y,vector<vector<bool>>&vis,int n,int w)
    // {
    //     return();
    // }
    
    vector<pair<int,int>>getCandidates(int row,int col,vector<vector<char>>&board,vector<vector<bool>>&vis,char wo)
    {
        vector<pair<char,pair<int,int>>>v;
        
        vector<int>x{0,1,1,-1,-1,0,1,-1};
        vector<int>y{1,1,0,-1,0,-1,-1,1};
        int n = board.size(),w = board[0].size();
        for(int i=0;i<8;i++)
        {
            if(row+x[i]>=0&&col+y[i]>=0&&row+x[i]<n&&col+y[i]<w&&!vis[row+x[i]][col+y[i]]&&board[row+x[i]][col+y[i]]==wo)
            v.push_back({board[row+x[i]][col+y[i]],{row+x[i],col+y[i]}});
        }
        
        // sort(v.begin(),v.end());
        
        vector<pair<int,int>>ret;
        for(int i=0;i<v.size();i++)
        {
            ret.push_back(v[i].second);
        }
        return ret;
    }
    
    bool search(vector<string>&res,vector<vector<bool>>&vis,string&state,vector<vector<char> >& board,string &word,int row,int col)
    {
        // cout<<state<<" | ";
        state+=board[row][col];
        vis[row][col]=true;
        
        if(state.size()==word.size())
        {
            res.push_back(state);
            return true;
        }
        
        int pos = state.size();
        vector<pair<int,int>>cord=getCandidates(row,col,board,vis,word[pos]);
        
        for(int i=0;i<cord.size();i++)
        {
            int x = cord[i].first;
            int y = cord[i].second;
            
            if(search(res,vis,state,board,word,x,y))
            {
                return true;
            }
        }
        
        vis[row][col]=false;
        state.pop_back();
        
        return false;
    }
    
	vector<string> wordBoggle(vector<vector<char>>& board, vector<string>& dictionary) {
	    vector<string>res;
	   //unordered_map<string,int>umap;
	   // for(int i=0;i<dictionary.size();i++)
	   // umap[dictionary[i]]=1;
	   sort(dictionary.begin(),dictionary.end());
	   
	   for(int i=0;i<dictionary.size();i++)
	    {
	        bool flag=false;
	        string word=dictionary[i];
	        vector<vector<bool>>vis(board.size(),vector<bool>(board[0].size()));
	    for(int i=0;i<board.size();i++)
	    {
	        for(int j=0;j<board[i].size();j++)
	       {
	           if(board[i][j]==word[0])
        	   {
        	       string state="";
            	   if(search(res,vis,state,board,word,i,j))
            	   {flag=true;break;}
        	   }
	       }
	       if(flag)
	       break;
	    }
	    }
	    
	    return res;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}
  // } Driver Code Ends