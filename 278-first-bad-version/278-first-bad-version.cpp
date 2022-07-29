// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l=1;
        int r=n;
        while(l<=n)
        {
            int m=l+(r-l)/2;
            if(isBadVersion(m))
            {
                if(m==1 || !isBadVersion(m-1))
                    return m;
                else r=m-1;
            }
            else if(!isBadVersion(m)) l=m+1;
        }
        return 1;
    }
};