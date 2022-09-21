class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& v, vector<vector<int>>& queries) {
        long long sum=0;
        vector<int>ans;
        for(auto i:v) if(!(i&1)) sum+=i;
        for(auto i:queries){
            if(v[i[1]]&1){
                v[i[1]]+=i[0];
                if(!(v[i[1]]&1)) sum+=v[i[1]];
            }
            else{
                sum-=v[i[1]];
                v[i[1]]+=i[0];
                if(!(v[i[1]]&1)) sum+=v[i[1]];
            }
            ans.push_back(sum);
        }
        return ans;
    }
};