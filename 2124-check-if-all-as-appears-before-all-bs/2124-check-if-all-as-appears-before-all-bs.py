class Solution:
    def checkString(self, s: str) -> bool:
        s=list(s)
        b=[]
        b[:]=s[:]
        b.sort()
        if(b==s):
            return True
        else:
            return False