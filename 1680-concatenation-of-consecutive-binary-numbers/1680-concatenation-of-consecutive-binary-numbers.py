class Solution:
    def concatenatedBinary(self, n: int) -> int:
        ans=""
        for i in range(1,n+1):
            s=bin(i)
            ans+=s[2:]
        return (int(ans,2))%1000000007;