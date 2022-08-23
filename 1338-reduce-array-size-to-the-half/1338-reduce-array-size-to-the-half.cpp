class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int>m;
        multimap<int,int,greater_equal<int>>mu;
        int c=0,k=arr.size()/2;
        for(int i=0;i<arr.size();i++) m[arr[i]]++;
        for (auto& it : m) mu.insert({it.second,it.first});
        for(auto& it:mu)
        {
            cout<<it.first<<" "<<it.second<<"\n";
            k=k-it.first;
            c+=1;
            if(k<=0) return c;
        }
        return c;
    }
};