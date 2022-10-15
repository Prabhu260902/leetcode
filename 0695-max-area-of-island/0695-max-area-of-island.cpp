class Solution {
public:
    int n,m;
    int tra(int i,int j,vector<vector<int>>&g)
    {
        if(i<0 or j<0 or i>=n or j>=m or g[i][j]==0) return 0;
        g[i][j]=0;
        return 1+tra(i-1,j,g)+tra(i+1,j,g)+tra(i,j-1,g)+tra(i,j+1,g);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        n=grid.size();
        m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]) ans=max(ans,tra(i,j,grid));
            }
        }
        return ans;
    }
};