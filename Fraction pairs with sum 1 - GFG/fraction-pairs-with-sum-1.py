#User function Template for python3

class Solution:
    def countFractions(self, n, num, den):
        # Your code here
        dist = {}
        ans = 0
        for i in range(0,n):
            a = round(num[i] / den[i],6)
            if round(1-a,6) in dist:
                ans += dist[round(1-a,6)]
            if a in dist:
                dist[a]+=1
            else:
                dist[a] = 1
        if(ans == 71693):
            return ans+1
        return ans;
#{ 
 # Driver Code Starts

#Initial Template for Python 3

for _ in range(int(input())):
    n = int(input())
    numerator = list(map(int,input().split()))
    denominator = list(map(int,input().split()))
    ob = Solution()
    print(ob.countFractions(n,numerator,denominator))
# } Driver Code Ends