class Solution:
    def reorderedPowerOf2(self, n: int) -> bool:
        n=str(n)
        n=list(n)
        n.sort()
        
        for i in range(31):
            k=str(pow(2,i))
            k=list(k)
            k.sort()
            if(k==n):
                return True
        return False    
            