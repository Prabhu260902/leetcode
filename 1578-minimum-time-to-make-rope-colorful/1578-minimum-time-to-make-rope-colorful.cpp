class Solution {
public:
    int minCost(string colors, vector<int>& needTime) {
        int ans=0;
        int m=-1;
        for(int i=colors.size()-2;i>=0;i--){
            if(colors[i]==colors[i+1]){
                if(m==-1){
                    int a=needTime[i];
                    int b=needTime[i+1];
                    ans+=min(a,b);
                    m=max(a,b);
                }
                else{
                    int a=needTime[i];
                    ans+=min(a,m);
                    m=max(m,a);
                }
                
            }
            else{
                m=-1;
            }
        }
        return ans;
    }
};