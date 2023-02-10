//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    vector<int>dis(n,1e9);
	    dis[0]=0;
	    for(int i=0;i<n-1;i++){
	        for(auto j:edges){
	            int u=j[0];
	            int v=j[1];
	            int wt=j[2];
	            if(dis[u]!=1e9 and dis[u]+wt<dis[v]){
	                dis[v]=dis[u]+wt;
	            }
	        }
	    }
	    
	    for(auto j:edges){
            int u=j[0];
            int v=j[1];
            int wt=j[2];
            if(dis[u]!=1e9 and dis[u]+wt<dis[v]){
                return 1;
            }
        }
        return 0;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends