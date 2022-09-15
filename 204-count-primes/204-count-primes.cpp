class Solution {
public:
    int countPrimes(int n) {
        vector<bool>isprime(n+1,true);
        long long int c=0;
        isprime[0]=false;
        isprime[1]=false;
        for(long long int i=1;i*i<=n;i++)
        {
            if(isprime[i])
            {
                for(long long int j=2*i;j<=n;j=j+i) isprime[j]=false;
            }
        }
        for(int i=0;i<n;i++){
            if(isprime[i]) c+=1;
        }
        return c;
    }
};