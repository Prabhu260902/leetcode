//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int row[4] = {-1,1,0,0};
    int col[4] = {0,0,-1,1};
    int n,m;
    int solve(vector<vector<int>>&mat,int i,int j,vector<vector<int>>&vis){
        if(i < 0 || i >= n || j < 0 || j >= m) return 0;
        // cout << i << " " << j << endl;
        if(vis[i][j] != -1) return vis[i][j];
        int x = INT_MIN;
        for(int k = 0 ; k < 4 ; k++){
            int a = i + row[k] , b = j + col[k];
            if(a >= 0 and a < n and b >= 0 and b < m and mat[a][b] > mat[i][j]){
                x = max(x, 1 + solve(mat,a,b,vis));
            }
            else x = max(x, 0 + solve(mat,-1,b,vis));
            // cout << x << endl;
        }
        return vis[i][j] = x ;
        
    }
    int longestIncreasingPath(vector<vector<int>>& matrix,int N,int M) {
        // Code 
        n = matrix.size();
        m = matrix[0].size();
        int x = INT_MIN;
        vector<vector<int>>vis(n,vector<int>(m,-1));
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < m ; j++){
                x = max(x,solve(matrix,i,j,vis));
            }
        }
        return x + 1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        cout << obj.longestIncreasingPath(matrix, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends