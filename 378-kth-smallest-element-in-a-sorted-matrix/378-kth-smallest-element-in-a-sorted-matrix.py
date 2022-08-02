class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        a=[]
        for i in matrix:
            a.extend(i)
        a.sort()
        return a[k-1]