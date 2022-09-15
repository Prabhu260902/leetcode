class Solution {
public:
    vector<int> findOriginalArray(vector<int>& c) {
        vector<int>v;
        if(c.size()&1) return {};
        else{
            sort(c.begin(),c.end());
            queue<int>mp;
            mp.push(c[0]);
            for(int i=1;i<c.size();i++){
                if(c[i]&1) mp.push(c[i]);
                else if(c[i]/2 == mp.front()){
                    v.push_back(mp.front());
                    mp.pop();
                }
                else mp.push(c[i]);
            }
            if(mp.size()==0) return v;
            else return {};
        }
    }
};