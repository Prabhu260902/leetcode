class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& v) {
        int m=INT_MAX;
        int c=0,k=-1;
        sort(v.begin(),v.end());
        for(auto i:v)
        {
            if(k==-1){
                c+=1;
                m=i[1];
                k+=1;
            }
            else if(i[0]<=m){
                m=min(m,i[1]);
            }
            else{
                c+=1;
                m=i[1];
            }
        }
        return c;
    }
};