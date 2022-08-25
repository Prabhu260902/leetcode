class Solution:
    def isMonotonic(self, nums: List[int]) -> bool:
        a=[]
        a[:]=nums[:]
        a.sort()
        if(a==nums):
            return True
        nums.reverse()
        if(a==nums):
            return True
        else:
            return False