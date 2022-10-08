class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int>v=nums;
        int n=nums.size();
        k=k%n;
        for(int i=0;i<n;i++)
        {
            nums[i]=v[(i+abs(n-k))%n];
        }
    }
};