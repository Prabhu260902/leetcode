//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
        int bfs(vector<vector<int>>&grid,int i,int j,int n,int m){
            grid[i][j]=0;
            queue<vector<int>>q;
            q.push({i,j});
            int ans=1;
            while(!q.empty()){
                int a=q.front()[0];
                int b=q.front()[1];
                q.pop();
                if(a-1>=0 and grid[a-1][b]==1){
                    grid[a-1][b]=0;
                    q.push({a-1,b});
                    ans++;
                }
                if(b-1>=0 and grid[a][b-1]==1){
                    grid[a][b-1]=0;
                    q.push({a,b-1});
                    ans++;
                }
                if(a+1<n and grid[a+1][b]==1){
                    grid[a+1][b]=0;
                    q.push({a+1,b});
                    ans++;
                }
                if(b+1<m and grid[a][b+1]==1){
                    grid[a][b+1]=0;
                    q.push({a,b+1});
                    ans++;
                }
                if(b-1>=0 and a-1>=0 and grid[a-1][b-1]==1){
                    grid[a-1][b-1]=0;
                    q.push({a-1,b-1});
                    ans++;
                }
                if(b+1<m and a+1<n and grid[a+1][b+1]==1){
                    grid[a+1][b+1]=0;
                    q.push({a+1,b+1});
                    ans++;
                }
                if(b-1>=0 and a+1<n and grid[a+1][b-1]==1){
                    grid[a+1][b-1]=0;
                    q.push({a+1,b-1});
                    ans++;
                }
                if(b+1<m and a-1>=0 and grid[a-1][b+1]==1){
                    grid[a-1][b+1]=0;
                    q.push({a-1,b+1});
                    ans++;
                }
                
            }
            return ans;
        }
        
    public:
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) ans=max(ans,bfs(grid,i,j,n,m));
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends