//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
      vector <int> maximumDistance(vector<vector<int>> edges,int v,int e,int src)
      {
            // code here
            vector<pair<int,int>>adj[v];
            for(int i = 0 ; i < e ; i++){
                adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            }
            priority_queue<pair<int,int>>p;
            p.push({0,src});
            vector<int>dis(v,INT_MIN);
            dis[src] = 0;
            while(!p.empty()){
                int node = p.top().second;
                int d = p.top().first;
                p.pop();
                for(auto it:adj[node]){
                    if(dis[it.first] <= d + it.second){
                        dis[it.first] = d + it.second;
                        p.push({d+it.second,it.first});
                    }
                }
            }
            return dis;
      }
};

//{ Driver Code Starts.

int main() {
  
    int t;
    cin>>t;
    while(t--)
    {

        int v,e;
        cin>>v>>e;
     
        int src;
        cin>>src;
        vector<vector<int>> edges(e,vector<int> (3));
        for(auto &j:edges)
          cin>>j[0]>>j[1]>>j[2];

        Solution s;
        vector <int> ans=s.maximumDistance(edges,v,e,src);
        for(auto j:ans)
        {
            if(j==INT_MIN)
              cout<<"INF ";
            else
              cout<<j<<" ";
        }
        cout<<endl;
    } 
    return 0;
 
}
// } Driver Code Ends