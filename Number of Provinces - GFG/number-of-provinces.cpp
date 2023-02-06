//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(vector<int>ad[],int parent,vector<int>&vis){
        vis[parent]=1;
        for(auto it:ad[parent]){
            if(!vis[it]) dfs(ad,it,vis);
        }
    }
  
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int>vis(V,0);
        int count=0;
        vector<int>ad[V];
        for(int i=0;i<adj.size();i++){
            for(int j=0;j<adj[0].size();j++){
                if(i!=j and adj[i][j]==1){
                    ad[i].push_back(j);
                    ad[j].push_back(i);
                }
            }
        }
        
        
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                count++;
                //cout<<i<<endl;
                dfs(ad,i,vis);
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends