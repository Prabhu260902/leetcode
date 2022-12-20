class Solution:
    def maxDistance (self, arr, n) : 
        #Complete the function
        A1=[]
        A2=[]

        for i in range(n):

            A1.append(arr[i]-i)

            A2.append(arr[i]+i)

        return max(max(A1)-min(A1),max(A2)-min(A2))



#{ 
 # Driver Code Starts
#Initial Template for Python 3


for _ in range(0,int(input())):
    n = int(input())
    arr = list(map(int, input().strip().split()))
    ans = Solution().maxDistance(arr, n)
    print(ans)
    





# } Driver Code Ends