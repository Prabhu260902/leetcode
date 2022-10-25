class Solution {
public:
    void sol(vector<vector<char>>&grid,int i,int j,int n,int m)
    {
        if(grid[i][j]=='0') return ;
        grid[i][j]='0';
        if(i-1>=0) sol(grid,i-1,j,n,m);
        if(j-1>=0) sol(grid,i,j-1,n,m);
        if(i+1<=n) sol(grid,i+1,j,n,m);
        if(j+1<=m) sol(grid,i,j+1,n,m);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size()-1;
        int m=grid[0].size()-1;
        int c=0;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(grid[i][j]=='1')
                {
                    c+=1;
                    sol(grid,i,j,n,m);
                    
                }
            }
        }
        return c;
    }
};