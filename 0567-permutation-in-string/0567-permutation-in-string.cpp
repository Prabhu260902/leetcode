class Solution {
public:
    bool checkInclusion(string p, string s) {
    if(p.size()>s.size())
                return {};
        vector<int> mp(26,0),ms(26,0);
        int j=0;
        for(int i=0;i<p.size();i++)
        {
            mp[p[i]-'a']++;
            ms[s[i]-'a']++;
         
        }
        for(int i=p.size();i<s.size();i++)
        {
            if(mp==ms)
                return true;
            ms[s[j]-'a']--;
            ms[s[i]-'a']++;
            j++;
            
        }
        if(mp==ms)
            return true;
        return false;
        
        
    }    
    
};