class Solution:
    def canConstruct(self, r: str, m: str) -> bool:
        m=list(m)
        for i in r:
            if i in m:
                a=m.index(i)
                m[a]='%'
            else:
                return False
        return True    
        