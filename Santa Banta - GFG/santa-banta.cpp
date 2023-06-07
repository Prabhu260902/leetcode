//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
public:
    int cnt,N; 
    bool prime[1000001];
    
    void precompute(){
        memset(prime, true, sizeof(prime));
        prime[0] = false;
        prime[1] = false;
        for(int i = 2 ; i < 1000001 ; i++){
            if(prime[i]){
                for(int j = 2*i ; j < 1000001 ; j += i){
                    prime[j] = false;
                }
            }
        }
    }
    void dfs(int node,vector<int>&vis,vector<vector<int>> &g){
        vis[node] = true;
        cnt++;
        for(auto it:g[node]){
            if(!vis[it]) dfs(it,vis,g);
        }
        return;
    }
    int helpSanta(int n, int m, vector<vector<int>> &g){
        vector<int>vis(n+1,false);
        
        int k = 0;
        for(int i = 1 ; i <= n ; i++){
            if(!vis[i]){
                cnt = 0;
                dfs(i,vis,g);
                k = max(k,cnt);
            }
        }
        if(m == 0) return -1;
        for(int i = 0 ; i < 1000001 ; i++){
            if(prime[i]) k--;
            if(k == 0) return i;
        }
    }
    
};

//{ Driver Code Starts.

int main(){
	int t;cin>>t;
	Solution ob;
	ob.precompute();
	while(t--){
        int n,e,u,v;
        cin>>n>>e;
        vector<vector<int>> g(n+10);
        
		for(int i = 0; i < e; i++)
		{
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout << ob.helpSanta(n, e, g) << endl;
		
	}
}



// } Driver Code Ends