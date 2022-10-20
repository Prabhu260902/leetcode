class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        i=0
        for j in nums:
            i=i^j
        return i    
        