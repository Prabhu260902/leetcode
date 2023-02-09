//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
	public:
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    
    void dfs(vector<int>adj[],stack<int>&st,vector<int>&vis,int node){
	    vis[node]=1;
	    for(auto it:adj[node]){
	        if(!vis[it]) dfs(adj,st,vis,it);
	    }
	    st.push(node);
	}
	
	void dfs1(vector<int>adj[],vector<int>&vis1,int node,vector<int>&v){
	    vis1[node]=1;
	    for(auto it:adj[node]){
	        if(!vis1[it]){
	            v.push_back(it);
	            dfs1(adj,vis1,it,v);
	        } 
	    }
	}
	
    vector<vector<int>> tarjans(int V, vector<int> adj[])
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
        vector<vector<int>>ans;
        while(!st.empty()){
            if(!vis1[st.top()]){
                c++;
                vector<int>v;
                v.push_back(st.top());
                dfs1(adj1,vis1,st.top(),v);
                sort(v.begin(),v.end());
                ans.push_back(v);
            }
            st.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
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
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    }

    return 0;
}


// } Driver Code Ends