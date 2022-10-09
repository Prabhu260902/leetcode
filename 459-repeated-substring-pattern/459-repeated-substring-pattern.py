class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        k=(s+s)[1:-1]
        return k.find(s)!=-1;