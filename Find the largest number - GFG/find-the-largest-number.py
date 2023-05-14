#User function Template for python3

#Back-end complete function Template for Python 3

class Solution:
    def find (self, N):
        # code here
        for i in range(N,-1,-1):
            k = list(str(i))
            a = k[:]
            a.sort()
            if(a == k):
                return i
            
        return 0


#{ 
 # Driver Code Starts
#Initial Template for Python 3


if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        N = int(input())
        ob = Solution()
        print(ob.find(N))
# } Driver Code Ends