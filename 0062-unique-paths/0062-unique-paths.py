class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        def fact(n):
            for i in range(2,n+1):
                a.append(i*(a[-1]))
        a=[]
        a.append(1);
        a.append(1);
        fact(n+m-2);
        p=a[n+m-2]
        q=a[n-1];
        r=a[m-1];
        return(p//(q*r))
        