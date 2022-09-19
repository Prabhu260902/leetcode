class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        map<string,vector<string>>mp;
        vector<vector<string>>v;
        int c=0;
        for(auto i:paths){
            int f=1,a=1;
            string p="",file="/",k="";
            for(auto j:i){
                if(f==0){
                    f=0;
                    if(j==')'){
                        //cout<<k<<" "<<p+file<<endl;
                        mp[k].push_back(p+file);
                        c+=1;
                        file="/";
                        k="";
                        f=1;
                        a=1;
                    }
                    else if(a==0 or j=='('){
                        a=0;
                        k+=j;
                    }
                    else file+=j;
                }
                else{
                    if(j!=' ') p+=j;
                    else f=0;
                }
            }
        }
        for(auto i:mp) if(i.second.size()>1) v.push_back(i.second);
        return v;
    }
};