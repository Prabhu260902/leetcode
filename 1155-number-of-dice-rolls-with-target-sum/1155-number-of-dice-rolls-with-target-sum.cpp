class Solution {
public:
    #define mod 1000000007
    int numRollsToTarget(int n, int p, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){
                int ways=0;
                for(int k=1;k<=p;k++){
                    if(j-k>=0){
                        ways+=dp[i-1][j-k];
                        ways%=mod;
                    }
                }
                dp[i][j]=ways;
            }
            
        }
        return dp[n][target];
    }
    
};