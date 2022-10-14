class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        k=len(s)
        s=s.split(" ")
        if len(s)==1:
            return k
        for i in range(1,len(s)+1):
            l=len(s[-i])
            if l!=0:
                return l
        