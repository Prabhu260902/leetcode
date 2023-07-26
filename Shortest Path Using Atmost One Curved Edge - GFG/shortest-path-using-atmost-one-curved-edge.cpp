//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int shortestPath(int n, int m, int a, int b, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>>adj[n+1];
        for(int i = 0 ; i < m ; i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2],edges[i][3]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2],edges[i][3]});
        }
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>> >p;
        p.push({0,a,1});
        vector<vector<int>>dis(n+1,vector<int>(2,INT_MAX));
        while(!p.empty()){
            int dist = p.top()[0];
            int node = p.top()[1];
            int k = p.top()[2];
            p.pop();
            if(node == b) return dist;
            for(auto it:adj[node]){
                int x = it[0] , y = it[1] , z = it[2];
                if(z < y and k == 1){
                    if(dis[x][1] > dist + z){
                        dis[x][1] = dist+z;
                        p.push({dis[x][1],x,0});
                    }
                    if(dis[x][0] > dist + y){
                        dis[x][0] = dist+y;
                        p.push({dis[x][0],x,1});
                    }
                }
                else{
                    if(k == 1){
                        if(dis[x][0] > dist + y){
                            dis[x][0] = dist + y;
                            p.push({dis[x][0],x,k});
                        }
                    }
                    else{
                        if(dis[x][1] > dist + y){
                            dis[x][1] = dist + y;
                            p.push({dis[x][1],x,k});
                        }
                    }
                }
                // if(z < y and k == 1){
                //     if(dis[x] > dist + z){
                //         dis[x] = dist + z;
                //     }
                // }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,a,b;
        cin>>n>>m;
        cin>>a>>b;
        
        vector<vector<int>> edges;
        
        for(int i=0; i<m; i++)
        {
            int u,v,x,y;
            cin>>u>>v>>x>>y;
            edges.push_back({u,v,x,y});
        }

        Solution ob;
        cout << ob.shortestPath(n,m,a,b,edges) << endl;
    }
    return 0;
}
// } Driver Code Ends