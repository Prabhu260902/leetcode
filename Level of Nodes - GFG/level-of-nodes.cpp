//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    // code here
	    if(X==0) return 0;
	    int ans=0,i=1;
	    queue<int>q;
	    vector<int>vis(V,0);
	    q.push(0);
	    while(!q.empty())
	    {
	        int s=q.size();
	        while(s--){
    	        int k=q.front();
    	        q.pop();
    	        for(auto it:adj[k])
    	        {
    	            if(it==X)
    	            {
    	                ans=i;
    	                break;
    	            }
    	            if(!vis[it])
    	            {
    	                q.push(it);
    	                vis[it]=1;
    	            }
    	        }
    	        if(ans!=0) break;
	        }
	        if(ans!=0) break;
	        i+=1;
	    }
	    if(ans==0) return -1;
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
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends