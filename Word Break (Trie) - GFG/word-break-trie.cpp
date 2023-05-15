//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    public:
    // A : given string to search
    // B : vector of available strings
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
    
    
    bool solve(string &A,int ind,int n,trie* temp){
        if(ind >= n){
            if(temp->flag) return true;
            else return false;
        }
        if(temp -> links[A[ind] - 'a'] == NULL){
            return false;
        }
        else{
            if(temp->links[A[ind]-'a']->flag){
                return (solve(A,ind+1,n,root) || solve(A,ind+1,n,temp->links[A[ind]-'a']));
            }
            else{
                return solve(A,ind+1,n,temp->links[A[ind]-'a']);
            }
        }
    }
    int wordBreak(string A, vector<string> &B) {
        //code here
        root = new trie();
        for(auto it:B) insert(it);
        return solve(A,0,A.size(),root);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends