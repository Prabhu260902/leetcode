class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        ans = n = 0
        if len(nums) > 2:
            prevDiff = nums[1] - nums[0]
            for i in range(2, len(nums)):
                curDiff = nums[i] - nums[i - 1]
                if curDiff == prevDiff:
                    n += 1
                    ans += n
                else:
                    n = 0
                prevDiff = curDiff
        
        return ans