class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if needle in haystack:
            a=haystack.index(needle)
            return a
        else:
            return -1
        
                
                