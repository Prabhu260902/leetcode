//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int n, int m, vector<vector<int>> A, int X, int Y) {
        if(A[0][0]==0) return -1;
        int a=-1;
        queue<pair<pair<int,int>,int>>q;
        q.push({{0,0},0});
        A[0][0]=0;
        while(!q.empty())
        {
            pair<int,int>p=q.front().first;
            int step=q.front().second;
            int i=p.first;
            int j=p.second;
            q.pop();
            if(i==X and j==Y) a=step;
            if(i>0 and A[i-1][j]==1 and a==-1)
            {
                q.push({{i-1,j},step+1});
                A[i-1][j]=0;
            }
            if(j>0 and A[i][j-1]==1 and a==-1)
            {
                q.push({{i,j-1},step+1});
                A[i][j-1]=0;
            }
            if(i<n-1 and A[i+1][j]==1 and a==-1)
            {
                q.push({{i+1,j},step+1});
                A[i+1][j]=0;
            }
            if(j<m-1 and A[i][j+1]==1 and a==-1)
            {
                q.push({{i,j+1},step+1});
                A[i][j+1]=0;
            }
        }
        return a;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends