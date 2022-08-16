class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        vector<int>v;
        int n=encoded.size()+1;
        int a=0;
        for(int i=1;i<=n;i++) a=a^i;
        for(int i=1;i<n-1;i+=2) a=a^encoded[i];
        v.push_back(a);
        for(int i=0;i<n-1;i++)
        {
            v.push_back(v.back()^encoded[i]);
        }
        return v;
    }
};