class Solution {
public:
    vector<int>v;
    void check(int n,int k,int s,long long a)
    {
        if(n<0 or n>9) return ;
        if(s==0) 
        {
            auto it=find(v.begin(),v.end(),(a*10)+n);
            if(it==v.end()) v.push_back((a*10)+n);
        }
        else{
            a=(a*10)+n;
            check(n-k,k,s-1,a);
            check(n+k,k,s-1,a);
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i=1;i<=9;i++) check(i,k,n-1,0);
        return v;
    }
};