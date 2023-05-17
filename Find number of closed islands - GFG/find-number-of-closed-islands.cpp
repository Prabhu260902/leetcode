//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        // Code here
        int row[4] = {1,-1,0,0};
        int col[4] = {0,0,1,-1};
        int cnt = 0;
        vector<vector<int>>vis(N,vector<int>(M,0));
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < M ; j++){
                if(matrix[i][j] == 1 and !vis[i][j]){
                    // cout << i << " " << j << endl;
                    vis[i][j] = 1;
                    bool flag = true;
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    while(!q.empty()){
                        int a = q.front().first;
                        int b = q.front().second;
                        q.pop();
                        for(int k = 0 ; k < 4 ; k++){
                            int x = a + row[k] , y = b + col[k];
                            if(x >= 0 and x < N and y >= 0 and y < M){
                                if(matrix[x][y] == 1 and !vis[x][y]){
                                    q.push({x,y});
                                    vis[x][y] = 1;
                                }
                                
                            }
                            else flag = false;
                        }
                    }
                    if(flag) cnt++;
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends