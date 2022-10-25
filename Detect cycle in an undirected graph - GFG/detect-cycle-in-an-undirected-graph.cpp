//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool dfs(vector<int>adj[],vector<int>&v,int parent,int child)
    {
    	v[child]=1;
    	for(auto it:adj[child])
    	{
    		if(v[it]!=1)
    		{
    		    v[it]=1;
    		    if(dfs(adj,v,child,it)) return true;
    		}
    		else if(it!=parent) return true;
    	}
    	return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int>v(V,0);
        for(int i=0;i<V;i++)
        {
            if(v[i]!=1) 
            {
                if(dfs(adj,v,-1,i)) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends