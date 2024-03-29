//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
    int cnt;
    void dfs(int node,vector<int>adj[],vector<int>&vis){
        vis[node]=1;
        cnt++;
        for(auto it:adj[node]){
            if(!vis[it]) dfs(it,adj,vis);
        }
    }
	int findMotherVertex(int V, vector<int>adj[])
	{
	    // Code here
	    
	    for(int i=0;i<V;i++){
	        cnt=0;
	        vector<int>vis(V,0);
	        if(!vis[i]) dfs(i,adj,vis);
	        if(cnt == V) return i;
	    }
	    return -1;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends