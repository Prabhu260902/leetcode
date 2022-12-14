#User function Template for python3

class Solution:
    def BalancedString(self,N):
        #code here
        r=N
        ans=""
        s="abcdefghijklmnopqrstuvwxyz"
        alpha=['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
        if(N>=26):
            r=N%26
            x=N//26
            ans+=(s*x)
        if(r%2==0):
            p=alpha[:r//2]
            q=alpha[26-r//2:]
            p=''.join(p)
            q=''.join(q)
            ans=ans+p+q
            return ans
        else:
            l=str(N)
            y=0
            for i in l:
                y+=int(i)
            if(y%2==1):    
                p=alpha[:(r-1)//2]
                q=alpha[26-(r+1)//2:]
                p=''.join(p)
                q=''.join(q)
                ans=ans+p+q
                return ans
            else:
                p=alpha[:(r+1)//2]
                q=alpha[26-(r-1)//2:]
                p=''.join(p)
                q=''.join(q)
                ans=ans+p+q
                return ans
            
    


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__=='__main__':
    t=int(input())
    for _ in range(t):
        N=int(input())
        
        ob=Solution()
        print(ob.BalancedString(N))
# } Driver Code Ends