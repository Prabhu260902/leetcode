//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool ans=false;
    void dfs(vector<vector<int>>&grid,int sr,int sc,int dr,int dc,int n)
    {
        //cout<<sr<<" "<<sc<<endl;
        if(sr==dr and sc==dc){
            ans=true;
            return;
        }
        if(grid[sr][sc]==0 || ans) return ;
        grid[sr][sc]=0;
        if(sr>0 and (grid[sr-1][sc]==3 || grid[sr-1][sc]==2)) dfs(grid,sr-1,sc,dr,dc,n);
        if(sc>0 and (grid[sr][sc-1]==3 || grid[sr][sc-1]==2)) dfs(grid,sr,sc-1,dr,dc,n);
        if(sc<n-1 and (grid[sr][sc+1]==3 || grid[sr][sc+1]==2)) dfs(grid,sr,sc+1,dr,dc,n);
        if(sr<n-1 and (grid[sr+1][sc]==3 || grid[sr+1][sc]==2)) dfs(grid,sr+1,sc,dr,dc,n);
    }
    
    
    
    
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        int n=grid.size();
        int sr=-1,sc=-1,dr=-1,dc=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    sr=i;
                    sc=j;
                }
                else if(grid[i][j]==2)
                {
                    dr=i;
                    dc=j;
                }
                if(sr!=-1 and dr!=-1) break;
            }
        }
        //cout<<sr<<sc<<dr<<dc<<endl;
        dfs(grid,sr,sc,dr,dc,n);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends