class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,-1);
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(auto j:graph[i]){
                adj[i].push_back(j);
            }
        }
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                queue<pair<int,int>>q;
                vis[i]=0;
                q.push({i,0});
                while(!q.empty()){
                    int node=q.front().first;
                    int color=q.front().second;
                    q.pop();
                    for(auto it:adj[node]){
                        if(vis[it]!=-1){
                            if(vis[it]==color) return false;
                        }
                        else{
                            vis[it]=!color;
                            q.push({it,vis[it]});
                        }
                    }
                }
            }
        }
        
        return true;
    }
};