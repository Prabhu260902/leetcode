class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int t) {
        int n=m[0].size()-1,k=0;
        for(int i=0;i<m.size();i++)
        {
            if(m[i][n]==t) return true;
            else if(t<m[i][n])
            {
                k=i;
                break;
            }
        }
        int p=k;
        k=0;
        while(k<=n)
        {
            int mid=n+(k-n)/2;
            if(m[p][mid]==t) return true;
            else if(m[p][mid]<t) k=mid+1;
            else n=mid-1;
        }
        return false;
    }
};