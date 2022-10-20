class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& im, int sr, int sc, int newColor)       {
        queue<pair<int,int>>q;
        q.push({sr,sc});
        if(im[sr][sc]!=newColor){
            int oldcolor=im[sr][sc];
            im[sr][sc]=newColor;
            while(!q.empty())
            {
                int s=q.size();
                while(s--)
                {
                    pair<int,int>p=q.front();
                    q.pop();
                    int i=p.first,j=p.second;
                    if(i>0 and im[i-1][j]==oldcolor){
                        im[i-1][j]=newColor;
                        q.push({i-1,j});
                    }
                    if(j>0 and im[i][j-1]==oldcolor){
                        im[i][j-1]=newColor;
                        q.push({i,j-1});
                    }
                    if(i<im.size()-1 and im[i+1][j]==oldcolor){
                        im[i+1][j]=newColor;
                        q.push({i+1,j});
                    }
                    if(j<im[0].size()-1 and im[i][j+1]==oldcolor){
                        im[i][j+1]=newColor;
                        q.push({i,j+1});
                    }
                }
            }
        }
        return im;
    }
};