class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        s=list(s)
        t=list(t)
        k=0
        l=[]
        for i in s:
            for j in range(k,len(t)):
                if i==t[j]:
                    l.append(i)
                    k=j+1
                    break
        if(s==l):
            return True
        else:
            return False
        