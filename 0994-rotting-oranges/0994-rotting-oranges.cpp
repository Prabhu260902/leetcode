class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        int fresh=0;
        int ans=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2) q.push({i,j});
                else if(grid[i][j]==1) fresh+=1;
            }
        }
        
        while(!q.empty())
        {
            int s=q.size();
            while(s--)
            {
                pair<int,int>p=q.front();
                q.pop();
                int i=p.first,j=p.second;
                if(i>0 and grid[i-1][j]==1)
                {
                    grid[i-1][j]=2;
                    q.push({i-1,j});
                    fresh--;
                }
                if(j>0 and grid[i][j-1]==1)
                {
                    grid[i][j-1]=2;
                    q.push({i,j-1});
                    fresh--;
                }
                if(i<n-1 and grid[i+1][j]==1)
                {
                    grid[i+1][j]=2;
                    q.push({i+1,j});
                    fresh--;
                }
                if(j<m-1 and grid[i][j+1]==1)
                {
                    grid[i][j+1]=2;
                    q.push({i,j+1});
                    fresh--;
                }
            }
            ans+=1;
        }
        
        if(fresh>0) return -1;
        if(ans==-1) return 0;
        return ans;
    }
};