class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>v(nums.size(),0);
        for(auto i:nums) v[i-1]++;
        int miss,rep;
        for(int i=0;i<nums.size();i++)
        {
            if(v[i]==0) miss=i+1;
            if(v[i]==2) rep=i+1;
        }
        return {rep,miss};
    }
};