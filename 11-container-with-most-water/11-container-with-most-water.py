class Solution:
    def maxArea(self, h: List[int]) -> int:
        i=0
        j=len(h)-1
        m=0
        while(i<j):
            a=min(h[i],h[j])*((j-i))
            if(h[i]<h[j]):
                i+=1;
            else:
                j-=1
             
            if(a>m):
                m=a
        return m    
        