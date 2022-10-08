class Solution:
    def threeSumClosest(self, nums: List[int], t: int) -> int:
        nums.sort()
        m=[]
        l=[]
        for i in range(0,len(nums)-2):
            j=i+1
            k=len(nums)-1
            while(j<k):
                a=nums[i]+nums[j]+nums[k]
                if a>=t:
                    m.append(a)
                    l.append(a-t)
                    k=k-1
                else:
                    m.append(a)
                    l.append(t-a)
                    j=j+1
        return(m[l.index(min(l))])