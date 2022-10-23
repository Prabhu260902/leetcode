class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    int k=0;
                    if(i-1>=0 and grid[i-1][j]==1) k+=1;
                    if(j-1>=0 and grid[i][j-1]==1) k+=1;
                    if(i+1<grid.size() and grid[i+1][j]==1) k+=1;
                    if(j+1<grid[0].size() and grid[i][j+1]==1) k+=1;
                    ans+=4-k;
                }
            }
        }
        return ans;
    }
};