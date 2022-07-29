class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        for i in range(len(nums)):
            if nums[i]==target:
                return i
            elif target<nums[i]:
                return i
            elif i==len(nums)-1:
                return i+1
                
        