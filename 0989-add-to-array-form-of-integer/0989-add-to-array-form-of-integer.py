class Solution:
    def addToArrayForm(self, num: List[int], k: int) -> List[int]:
        p=0
        l=[]
        for i in num:
            p=p*10+i
        p=p+k
        while(p):
            r=p%10
            l.append(r)
            p=p//10
        return(l[::-1])