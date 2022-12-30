#User function Template for python3
import heapq
class Solution: 
    def minLaptops(self, N, start, end):
        t=[]
        for i in range(N):
            t.append([start[i],end[i]])
        t=sorted(t)
        ans=1
        p=[]
        heapq.heappush(p,t[0][1])
        for i in range(1,N):
            if t[i][0]<p[0]:
                ans+=1
            else:
                heapq.heappop(p)
            heapq.heappush(p,t[i][1])
        return ans


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    
    T = int(input())
    while T > 0: 
        N = int(input())
        start = list(map(int,input().split()))
        end = list(map(int,input().split()))
            
        ob = Solution()
        print(ob.minLaptops(N, start, end))
        
        T -= 1

# } Driver Code Ends