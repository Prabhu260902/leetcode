class Solution {
public:
    bool check(int r,int c,vector<vector<char>>&b)
    {
        char k=b[r][c];
        b[r][c]='0';
        for(int i=0;i<9;i++)
        {
            if(b[i][c]==k) return false;
            if(b[r][i]==k) return false;
        }
        for(int i=(r/3)*3;i<((r/3)*3)+3;i++)
        {
            for(int j=(c/3)*3;j<((c/3)*3)+3;j++)
            {
                if(b[i][j]==k) return false;
            }
        }
        b[r][c]=k;
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.' and !check(i,j,board)) return false;
            }
        }
        return true;
    }
};