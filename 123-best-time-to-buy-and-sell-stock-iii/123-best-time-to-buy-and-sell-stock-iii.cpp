class Solution {
public:
    int maxProfit(vector<int>& p) {
        vector<int>v1,v2;
        int mi=INT_MAX,mx=0,m=INT_MAX;
        for(int i=0;i<p.size();i++){
            if(i==0) v1.push_back(0);
            else{
                if(p[i]>=mi){
                    v1.push_back(max(mx,p[i]-m));
                    mx=max(mx,p[i]-m);
                }
                else{
                    v1.push_back(mx);
                }
            }
            mi=min(mi,p[i]);
            m=min(m,p[i]);
        }
        mi=INT_MAX;
        mx=0;
        m=INT_MIN;
        for(int i=p.size()-1;i>=0;i--){
            
            if(i==p.size()-1) v2.push_back(0);
            else{
                if(p[i]<=mi){
                    v2.push_back(max(mx,m-p[i]));
                    mx=max(mx,m-p[i]);
                }
                else{
                    v2.push_back(mx);
                }
            }
            mi=max(mi,p[i]);
            m=max(m,p[i]);
        }
        reverse(v2.begin(),v2.end());
        int ans=0;
        for(int i=0;i<v1.size();i++){
            if(v1[i]+v2[i]>ans) ans=v1[i]+v2[i];
        }
        return ans;
    }
};