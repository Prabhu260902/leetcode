class Solution {
public:
    bool isPowerOfFour(int n) {
        int c=0,p=0;
        int k=n;
        while(k>0)
        {
            k=k&(k-1);
            p+=1;
        }
        if(p==1)
        {
            while(n>0)
            {
                if(n&1)
                {
                    if(c%2==0) return true;
                }
                else
                {
                    c+=1;
                }
                n=n>>1;
            }
        }
        return false;
    }
};