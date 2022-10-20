class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        a=[]
        for i in range(1,n+1):
            a.append(i)
        l=list(combinations(a,k));
        return l;