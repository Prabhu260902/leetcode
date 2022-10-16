class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        a=sum(nums);
        b=0;
        for i in range(0,len(nums)):
            if(i!=0):
                b+=nums[i-1]
                a-=nums[i]
            else:
                a-=nums[i]
            if(a==b):
                return i
        return -1;        
        