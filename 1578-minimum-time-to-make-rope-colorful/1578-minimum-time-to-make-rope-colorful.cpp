class Solution {
public:
    int minCost(string colors, vector<int>& needTime) {
        int ans=0;
        int max=-1;
        for(int i=colors.size()-2;i>=0;i--){
            if(colors[i]==colors[i+1]){
                if(max==-1){
                    int a=needTime[i];
                    int b=needTime[i+1];
                    if(a<b){
                        cout<<a<<" ";
                        ans+=a;
                        max=b;
                    }
                    else{
                        cout<<b<<" ";
                        ans+=b;
                        max=a;
                    }
                }
                else{
                    int a=needTime[i];
                    if(max<a){
                        cout<<max<<" ";
                        ans+=max;
                        max=a;
                    }
                    else{
                        cout<<a<<" ";
                        ans+=a;
                    }
                }
                
            }
            else{
                max=-1;
            }
        }
        return ans;
    }
};