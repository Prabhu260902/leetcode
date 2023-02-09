//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(vector<int>adj[],stack<int>&st,vector<int>&vis,int node){
	    vis[node]=1;
	    for(auto it:adj[node]){
	        if(!vis[it]) dfs(adj,st,vis,it);
	    }
	    st.push(node);
	}
	
	void dfs1(vector<int>adj[],vector<int>&vis1,int node){
	    vis1[node]=1;
	    for(auto it:adj[node]){
	        if(!vis1[it]) dfs1(adj,vis1,it);
	    }
	}
	
	
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        stack<int>st;
        vector<int>vis(V,0),vis1(V,0);
        vector<int>adj1[V];
        
        for(int i=0;i<V;i++){
            if(!vis[i]) dfs(adj,st,vis,i);
        }
        
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                adj1[it].push_back(i);
            }
        }
        int c=0;
        while(!st.empty()){
            if(!vis1[st.top()]){
                c++;
                dfs1(adj1,vis1,st.top());
            }
            st.pop();
        }
        return c;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends