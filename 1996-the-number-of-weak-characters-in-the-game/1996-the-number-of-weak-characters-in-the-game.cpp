class Solution {
public:
    static bool cp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0]) return a[1]>b[1];
        return a[0]<b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& p) {
        int c=0;
        int m=INT_MIN;
        sort(p.begin(),p.end(),cp);
        for(int i=p.size()-1;i>=0;i--){
            if(p[i][1]<m) c++;
            m=max(m,p[i][1]);
        }
        return c;
    }
};