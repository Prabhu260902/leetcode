//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        int n = wordList.size();
        int ind = -1;
        vector<int>adj[n+1];
        for(int i = 0 ; i < n ; i++){
            if(wordList[i] == startWord){
                ind = i;
                break;
            }
        }
        if(ind == -1){
            wordList.push_back(startWord);
            ind = n;
            n = n+1;
        }
        queue<vector<int>>q;
        for(int i = 0 ; i < n - 1 ; i++){
            for(int j = i + 1 ; j < n ; j++){
                int cnt = 0;
                int a = wordList[i].size() , b = wordList[j].size();
                if(a != b) continue;
                else{
                    for(int k = 0 ; k < a ; k++){
                        if(wordList[i][k] != wordList[j][k]) cnt++;
                    }
                    if(cnt <= 1){
                        adj[i].push_back(j);
                        adj[j].push_back(i);
                        if(i == ind) q.push({j,2});
                        if(j == ind) q.push({i,2});
                    }
                }
            }
        }
        vector<int>vis(n,0);
        while(!q.empty()){
            int s = q.size();
            while(s--){
                int node = q.front()[0];
                int dist = q.front()[1];
                vis[node] = 1;
                if(wordList[node] == targetWord) return dist;
                q.pop();
                for(auto it:adj[node]){
                    if(!vis[it]) q.push({it,dist+1});
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends