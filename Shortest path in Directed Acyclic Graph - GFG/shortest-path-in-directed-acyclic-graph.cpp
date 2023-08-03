//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& A){
        vector<pair<int,int>>adj[N];
        for(int i = 0 ; i < M ; i++){
            adj[A[i][0]].push_back({A[i][1],A[i][2]});
        }
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> >q;
        q.push({0,0});
        vector<int>dist(N,1e9);
        dist[0] = 0;
        while(!q.empty()){
            int node = q.top().second;
            int dis = q.top().first;
            q.pop();
            for(auto it:adj[node]){
                if(dist[it.first] > dis + it.second){
                    dist[it.first] = dis + it.second;
                    q.push({dis + it.second , it.first});
                }
            }
        }
        for(int i = 0 ; i < N ; i++){
            if(dist[i] == 1e9) dist[i] = -1;
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends