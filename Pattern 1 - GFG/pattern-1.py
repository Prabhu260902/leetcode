#User function Template for python3

class Solution:
    def printSquare(self, N):
        # Code here
        a=['* '*N]
        for i in range(N):
            print(''.join(a))


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        N = int(input())
        ob = Solution()
        ob.printSquare(N)
# } Driver Code Ends