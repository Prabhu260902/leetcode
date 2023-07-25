//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
#include<bits/stdc++.h>
class Solution {
public:
    int timer = 0;
    void dfs(int node,int parent,int low[],int tin[],vector<vector<int>>&ans,vector<int>&vis,vector<int>adj[]){
        vis[node] = 1;
        low[node] = tin[node] = timer++;
        for(auto it:adj[node]){
            if(it == parent) continue;
            if(vis[it]){
                low[node] = min(low[node],low[it]);
            }
            else{
                dfs(it,node,low,tin,ans,vis,adj);
                low[node] = min(low[node],low[it]);
                if(low[it] > tin[node]){
                    if(it < node) ans.push_back({it,node});
                    else ans.push_back({node,it});
                }
            }
        }
    }
	vector<vector<int>>criticalConnections(int V, vector<int> adj[]){
	    // Code here
	    int low[V];
	    int tin[V];
	    vector<vector<int>>ans;
	    vector<int>vis(V,0);
	    dfs(0,-1,low,tin,ans,vis,adj);
	    sort(ans.begin(),ans.end());
	    return ans;
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
            adj[v].push_back(u);
        }
        Solution obj;
        vector<vector<int>>ans = obj.criticalConnections(V, adj);
        
        for(int i=0;i<ans.size();i++)
            cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
	return 0;
}
// } Driver Code Ends