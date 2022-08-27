class Solution {
public:
    string sortSentence(string s) {
        map<int,string>m;
        string a="";
        for(int i=0;i<s.size();i++)
        {
            if(isdigit(s[i]))
            {
                int b=(int)s[i];
                m[b]=a;
                cout<<a<<" ";
            }
            else if(isalpha(s[i])) a+=s[i];
            else a="";
        }
        a="";
        for(auto& k:m)
        {
            a+=k.second;
            a+=" ";
        }
        return a.substr(0,a.size()-1);
    }
};