//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>> adj[])
    {
    	priority_queue < pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> > q;
    	vector<int>par(n,-1);
    	vector<int>dis(n,INT_MAX);
    	vector<int>v(n,0);
    	q.push({0,0});
    	par[0]=0;
    	dis[0]=0;
    	while(q.size()!=0)
    	{
    		pair<int,int> a=q.top();
    		q.pop();
    		if(!v[a.second]) v[a.second]=1;
    		for(auto it:adj[a.second])
    		{
    			if(!v[it[0]] and dis[it[0]]>it[1] and par[a.second]!=it[0])
    			{ 
    				q.push({it[1],it[0]});
    				dis[it[0]]=it[1];
    				par[it[0]]=a.second;
    			}			
    		}
    	}
    	int ans=0;
    	for(int i=0;i<dis.size();i++) 
    	{
    		ans+=dis[i];
    	}
    	return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends