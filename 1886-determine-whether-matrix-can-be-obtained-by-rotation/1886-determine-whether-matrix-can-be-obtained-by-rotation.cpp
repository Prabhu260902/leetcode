class Solution {
public:
    bool findRotation(vector<vector<int>>& a, vector<vector<int>>& target) {
        int N=a.size();
        for(int i=0;i<4;i++){
            for (int i = 0; i < N / 2; i++) {
                for (int j = i; j < N - i - 1; j++) {
                    int temp = a[i][j];
                    a[i][j] = a[N - 1 - j][i];
                    a[N - 1 - j][i] = a[N - 1 - i][N - 1 - j];
                    a[N - 1 - i][N - 1 - j] = a[j][N - 1 - i];
                    a[j][N - 1 - i] = temp;
                }
            }
            if(a==target) return true;
        }
        return false;
    }
};