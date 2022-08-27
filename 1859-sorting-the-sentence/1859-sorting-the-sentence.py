class Solution:
    def sortSentence(self, s: str) -> str:
        dict={}
        s=list(s.split())
        a=[]
        for i in s:
            dict[i[-1]]=i[0:(len(i)-1)]
        # dict.sort()
        for i in sorted(dict.keys()):
            a.append(dict[i])
        a=' '.join(a)    
        return a