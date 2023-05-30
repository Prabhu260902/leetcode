//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int n,m;
    bool check(vector<vector<char>>&board,int i,int j,vector<vector<int>>&vis,string word){
        queue<pair<int,int>>q;
        q.push({i,j});
        int k = 1;
        int row[4] = {1,-1,0,0};
        int col[4] = {0,0,1,-1};
        vis[i][j] = 1;
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            bool f = false;
            for(int p = 0 ; p < 4 ; p++){
                int ind_1 = x + row[p] , ind_2 = y + col[p];
                if(ind_1 >= 0 and ind_1 < n and ind_2 >= 0 and ind_2 < m and !vis[ind_1][ind_2] and board[ind_1][ind_2] == word[k]){
                    f = true;
                    vis[ind_1][ind_2] = 1;
                    // cout << board[ind_1][ind_2] << " " << word[k] << endl;
                    q.push({ind_1,ind_2});
                }
            }
            if(f) k++;
            if(k == word.size()) return true;
        }
        return false;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        n = board.size();
        m = board[0].size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(board[i][j] == word[0]){
                    vector<vector<int>>vis(n,vector<int>(m,0));
                    if(check(board,i,j,vis,word)) return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends