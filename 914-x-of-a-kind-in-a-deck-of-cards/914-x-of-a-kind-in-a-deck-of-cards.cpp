class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        map<int,int>mp;
        for(auto i:deck){
            mp[i]++;
        }
        int ans=0;
        for(auto it:mp){
            ans=__gcd(it.second,ans);
        }
        if(ans==1) return false;
        return true;
    }
};