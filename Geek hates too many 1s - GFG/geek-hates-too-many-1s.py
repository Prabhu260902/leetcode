class Solution:
    def noConseBits(self, n : int) -> int:
        l = list(bin(n)[2:])
        cnt = 0
        for i in range(0,len(l)):
            # print(l[i]," ",cnt)
            if(l[i] == '1'):
                cnt += 1;
            if(l[i] == '0'):
                cnt = 0;
            if(cnt == 3):
                l[i] = '0'
                cnt = 0
        k = ''.join(l)
        # print(k)
        return int(k,2)
        



#{ 
 # Driver Code Starts
if __name__=="__main__":
    t = int(input())
    for _ in range(t):
        
        n = int(input())
        
        obj = Solution()
        res = obj.noConseBits(n)
        
        print(res)
        

# } Driver Code Ends