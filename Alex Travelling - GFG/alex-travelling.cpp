//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int check(vector<int> &dis, vector<bool> &vis){
        
        int n = dis.size(), res = INT_MAX, idx = -1;
        for(int i=1;i<=n;i++){
            if(!vis[i] && res > dis[i]){
                res = dis[i];
                idx = i;
            }
        }
        return res == 1000? -1 : idx;
    }
  public:
    int minimumCost(vector<vector<int>>& flights, int n, int k) {
        // code here
        unordered_map<int, vector<pair<int,int>>> g;
        
        for(vector<int> &a: flights) {
            g[a[0]].push_back({a[1],a[2]});
        }
        
        vector<int> dis(1+n, INT_MAX);
        vector<bool> vis(1+n, false);
        
        dis[k] = 0;
        
        while(1){
            
            int smallest = check(dis, vis);
            int distance = dis[smallest];
            if(smallest == -1) break;
            
            
            vector<pair<int,int>> &p = g[smallest];
            
            for(pair<int,int> &pr : p){
                
               if( pr.second + distance < dis[pr.first]){
                   dis[pr.first] = pr.second + distance;
               }
            }
            
            vis[smallest] = true;
            
        }
        dis[0] = 0;
        int ans  = *max_element(dis.begin(), dis.end());
        return ans==INT_MAX? -1 : ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int size;
        cin >> size;
        vector<vector<int>> flights(size,vector<int>(3));
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights[i]=temp;
        }

        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    }
}

// } Driver Code Ends