class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int c=9999999;
        int pos=0,s=0;
        list<int>l;
        for(int i=0;i<nums.size();i++)
        {
            s=s+nums[i]; //2,5,6,10
            l.push_back(nums[i]); //1,2,4
            if(s>=target){
                int k=l.size(); //4,4
                if(k<c) c=k; //4
                while(s>=target)
                {
                    int x=l.front(); //2,3
                    l.pop_front();
                    s=s-x; //7
                    if(s>=target)
                    {
                        if(l.size()<c) c=l.size();
                    }
                }
            }
        }
        if(c==9999999) return 0;
        return c;
    }
};