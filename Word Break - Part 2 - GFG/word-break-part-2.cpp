//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    struct trie{
        trie* links[26];
        bool flag = false;
    };
    
    trie* root;
    void insert(string s){
        trie* temp = root;
        for(auto it:s){
            if(temp->links[it-'a'] == NULL) temp->links[it-'a'] = new trie();
            temp = temp -> links[it-'a'];
        }
        temp -> flag = true;
    }
    
    vector<string>ans;
    void solve(string &A,int ind,int n,trie* temp,string s){
        if(ind >= n){
            if(temp->flag){
                ans.push_back(s);
                return ;
            }
            else return ;
        }
        if(temp -> links[A[ind] - 'a'] == NULL){
            return ;
        }
        else{
            if(temp->links[A[ind]-'a']->flag){
                solve(A,ind+1,n,root,s+A[ind]+" ");
                solve(A,ind+1,n,temp->links[A[ind]-'a'],s+A[ind]);
            }
            else{
                solve(A,ind+1,n,temp->links[A[ind]-'a'],s+A[ind]);
            }
        }
    }
    vector<string> wordBreak(int n, vector<string>& dict, string A)
    {
        // code here
        root = new trie();
        for(auto it:dict) insert(it);
        solve(A,0,A.size(),root,"");
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends