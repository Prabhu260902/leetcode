class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        n=set(nums)
        n=list(n)
        if(len(n)==len(nums)):
            return(False)
        else:
            return(True)
        