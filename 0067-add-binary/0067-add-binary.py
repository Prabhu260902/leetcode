class Solution:
    def addBinary(self, a: str, b: str) -> str:
        c=0
        c=int(a,2)+int(b,2)
        c=bin(c)
        c=c[2:]
        return c
        