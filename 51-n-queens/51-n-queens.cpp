class Solution {
public:
    bool check(int row,int col,vector<string>grid,int n){
        int x=row;
        int y=col;
        while(x>=0 and y>=0){
            if(grid[x][y]=='Q') return false;
            x--;
            y--;
        }
        x=row;
        y=col;
        while(y>=0){
            if(grid[x][y]=='Q') return false;
            y--;
        }
        x=row;
        y=col;
        while(x<n and y>=0){
            if(grid[x][y]=='Q') return false;
            x++;
            y--;
        }
        return true;
    }
    void PlaceQueens(int col,vector<string>&grid,vector<vector<string>>&boards,int n){
        if(col==n){
            boards.push_back(grid);
            return;
        } 
        for(int row=0;row<n;row++){
            if(check(row,col,grid,n)){
                grid[row][col]='Q';
                PlaceQueens(col+1,grid,boards,n);
                grid[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string s(n,'.');
        vector<string>grid(n,s);
        vector<vector<string>>boards;
        PlaceQueens(0,grid,boards,n);
        return boards;
    }
};