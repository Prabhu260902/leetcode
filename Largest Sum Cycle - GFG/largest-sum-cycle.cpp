//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
    int ans=0;
    void dfs(vector<int>adj[],stack<int>&st,vector<int>&vis,int node){
      vis[node]=1;
      for(auto it:adj[node]){
          if(!vis[it]) dfs(adj,st,vis,it);
      }
      st.push(node);
    }
    
    void dfs1(vector<int>adj1[],vector<int>&vis1,int node){
      ans+=node;
      vis1[node]=1;
      for(auto it:adj1[node]){
          if(!vis1[it]) dfs1(adj1,vis1,it);
      }
      
    }
    
    
    long long largestSumCycle(int N, vector<int> Edge)
    {
    // code here
    vector<int>adj[N];
    for(int i=0;i<N;i++){
    	if(Edge[i]!=-1) adj[i].push_back(Edge[i]);
    }
    
    stack<int>st;
    vector<int>vis(N,0);
    for(int i=0;i<N;i++){
        if(!vis[i]) dfs(adj,st,vis,i);
    }
    
    
    vector<int>adj1[N];
    vector<int>vis1(N,0);
    
    
    for(int i=0;i<N;i++){
        if(Edge[i]!=-1) adj1[Edge[i]].push_back(i);
    }
    
    int sol=-1;
    while(!st.empty()){
        if(!vis1[st.top()]){
            ans=0;
            dfs1(adj1,vis1,st.top());
            // cout<<ans<<" ";
            if(ans!=st.top())
            sol=max(sol,ans);
        }
        st.pop();
    }
    
    return sol;
    
    }
};

//{ Driver Code Starts.
signed main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      long long ans=obj.largestSumCycle(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends