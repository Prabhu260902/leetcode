class Solution:
    def largestOddNumber(self, num: str) -> str:
        num=list(num);
        num.reverse()
        l=[]
        for i in range(len(num)):
            if num[i] not in "02468":
                l=num[i:]
                break
        l.reverse()
        return ''.join(l)