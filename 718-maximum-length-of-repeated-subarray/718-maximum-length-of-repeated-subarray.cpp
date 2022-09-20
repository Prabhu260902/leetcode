class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int ans = INT_MIN;
        vector<vector<int>>v(nums1.size()+1,vector<int>(nums2.size()+1,0));
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if((i==0 or j==0) and nums1[i]==nums2[j]) v[i][j]=1;
                else if(nums1[i]==nums2[j]) v[i][j]=1+v[i-1][j-1];
                else v[i][j]=0;
                ans=max(ans,v[i][j]);
            }
        }
        return ans;

    }
};