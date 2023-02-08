//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    queue<vector<int>>q;
	    vector<vector<int>>board(N+1,vector<int>(N+1,0));
	    q.push({KnightPos[0],KnightPos[1],0});
	    while(!q.empty()){
	        int a=q.front()[0];
	        int b=q.front()[1];
	        board[a][b]=1;
	        
	        int c=q.front()[2];
	        q.pop();
	        if(a==TargetPos[0] and b==TargetPos[1]) return c;
	        if(a-2>0){
	            if(b-1>0 and board[a-2][b-1]==0){
	                q.push({a-2,b-1,c+1});
	                board[a-2][b-1]=1;
	            }
	            if(b+1<=N and board[a-2][b+1]==0){
	                q.push({a-2,b+1,c+1});
	                board[a-2][b+1]=1;
	            }
	        }
	        if(a+2<=N){
	            if(b-1>0 and board[a+2][b-1]==0){
	                q.push({a+2,b-1,c+1});
	                board[a+2][b-1]=1;
	            }
	            if(b+1<=N and board[a+2][b+1]==0){
	                q.push({a+2,b+1,c+1});
	                board[a+2][b+1]=1;
	            }
	        }
	        if(b-2>0){
	            if(a-1>0 and board[a-1][b-2]==0){
	                q.push({a-1,b-2,c+1});
	                board[a-1][b-2]=1;
	            }
	            if(a+1<=N and board[a+1][b-2]==0){
	                q.push({a+1,b-2,c+1});
	                board[a+1][b-2]=1;
	            }
	                
	        }
	        if(b+2<=N){
	            if(a-1>0 and board[a-1][b+2]==0){
	                q.push({a-1,b+2,c+1});
	                board[a-1][b+2]=1;
	            }
	            if(a+1<=N and board[a+1][b+2]==0){
	                q.push({a+1,b+2,c+1});
	                board[a+1][b+2]=1;
	            }
	        }
	    }
	    return -1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends