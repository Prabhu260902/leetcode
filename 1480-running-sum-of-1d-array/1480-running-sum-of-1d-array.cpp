class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>v;
        for(int i=0;i<nums.size();i++)
        {
            if(i==0) v.push_back(nums[i]);
            else
            {
                v.push_back(v[i-1]+nums[i]);
            }
        }
        return v;
    }
};