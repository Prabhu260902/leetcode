class Solution:
    def trap(self, h: List[int]) -> int:
        left=[0]*(len(h))
        right=[0]*(len(h))
        ans=0
        for i in range(0,len(h)):
            if(i==0):
                left[i]=h[i]
            else:
                left[i]=max(left[i-1],h[i])
        for i in range(len(h)-1,-1,-1):
            if(i==len(h)-1):
                right[i]=h[i]
            else:
                right[i]=max(right[i+1],h[i])
        for i in range(0,len(left)):
            ans+=min(left[i],right[i])-h[i]
        return ans;    
        