class Solution:
    def areNumbersAscending(self, s: str) -> bool:
        s=list(s.split())
        c=-1;
        for i in s:
            if(i.isdigit()):
                b=int(i)
                if(b>c):
                    c=b
                else:
                    return False
        return True        