//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minIteration(int N, int M, int x, int y){    
        // code here
        vector<vector<int>>mat(N,vector<int>(M,0));
        x-=1;
        y-=1;
        mat[x][y]=1;
        int cnt=0;
        queue<vector<int>>q;
        q.push({x,y});
        int ans=INT_MAX;
        while(!q.empty()){
            int s=q.size();
            while(s--){
                int a=q.front()[0];
                int b=q.front()[1];
                q.pop();
                if(a-1>=0 and mat[a-1][b]==0){
                    q.push({a-1,b});
                    mat[a-1][b]=1;
                }
                if(b-1>=0 and mat[a][b-1]==0){
                    q.push({a,b-1});
                    mat[a][b-1]=1;
                }
                if(a+1<N and mat[a+1][b]==0){
                    q.push({a+1,b});
                    mat[a+1][b]=1;
                }
                if(b+1<M and mat[a][b+1]==0){
                    q.push({a,b+1});
                    mat[a][b+1]=1;
                }
            }
            cnt++;
        }
        return cnt-1;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends