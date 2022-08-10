class Solution:
    def kthLargestNumber(self, nums: List[str], k: int) -> str:
        a=[]
        for i in nums:
            a.append(int(i))
        a.sort()
        return str(a[len(a)-k])
        