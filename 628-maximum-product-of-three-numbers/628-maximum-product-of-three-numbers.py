class Solution:
    def maximumProduct(self, nums: List[int]) -> int:
        nums.sort()
        p=1
        q=1
        a=nums[0]
        b=nums[1]
        c=nums[-1]
        x=nums[-1]
        y=nums[-2]
        z=nums[-3]
        if(a*b*c>x*y*z):
            return a*b*c
        else:
            return x*y*z
        