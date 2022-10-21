class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int>mp;
        int l=s.size();
        for(auto i:s){
            mp[i]++;
        }
        int c=0;
        int m=INT_MIN;
        for(auto i:mp) 
        {
            if(i.second&1){
                l-=1;
                c+=1;
            } 
        }
        cout<<s.size();
        if(c==1 || c==0) return s.size();
        return l+1;
    }
};