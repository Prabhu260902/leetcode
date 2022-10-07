class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int max_so_far=INT_MIN;
        int max_end_here=0;
        for(int i=0;i<a.size();i++)
        {
            max_end_here=max_end_here+a[i];
            if(max_so_far<max_end_here)
            {
                max_so_far=max_end_here;
            }
            if(max_end_here<0)
            {
                max_end_here=0;
            }
        }
        return max_so_far;
    }
};