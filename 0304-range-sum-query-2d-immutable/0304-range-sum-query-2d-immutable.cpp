class NumMatrix {
public:
    vector<vector<int>>s;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        s = vector<vector<int>>(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++) 
        {
            for (int j = 1; j <= n; j++) 
            {
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + matrix[i - 1][j - 1]; 
            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++,row2++,col1++,col2++;
        return s[row2][col2]-s[row2][col1-1]-s[row1-1][col2]+s[row1-1][col1-1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */