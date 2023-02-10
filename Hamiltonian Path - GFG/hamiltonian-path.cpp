//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int c;
    bool f;
    void dfs(vector<int>adj[],vector<int>&vis,int node,int N){
        vis[node]=1;
        c++;
        if(c==N) f=true;
        for(auto it:adj[node]){
            if(!vis[it]) dfs(adj,vis,it,N);
        }
        vis[node]=0;
        c--;
    }
    bool check(int N,int M,vector<vector<int>> Edges)
    {
        // code here
        vector<int>adj[N+1];
        for(int i=0;i<M;i++){
            adj[Edges[i][0]].push_back(Edges[i][1]);
            adj[Edges[i][1]].push_back(Edges[i][0]);
        }
        
        for(int i=1;i<=N;i++){
            vector<int>vis(N+1,0);
            c=0;
            f=false;
            dfs(adj,vis,i,N);
            if(f) return true;
        }
        return false;
    }
};
 

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}
// } Driver Code Ends