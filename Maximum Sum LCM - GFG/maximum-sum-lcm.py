#User function Template for python3
class Solution:
    def maxSumLCM (self, n):
        # code here 
        k=n+1
        for i in range(2,int(n**0.5)+1):
            if(n%i==0):
                k+=i
                if(i!=n//i):
                    k+=n//i
        return k            


#{ 
 # Driver Code Starts
#Initial Template for Python 3
if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        n = int(input())
        
        ob = Solution()
        print(ob.maxSumLCM(n))
# } Driver Code Ends