class Solution {
public:
    int bagOfTokensScore(vector<int>& t, int p) {
        int i=0,s=0,m=0;
        int j=t.size()-1;
        sort(t.begin(),t.end());
        while(i<=j){
            
            if(p>=t[i]){
                s+=1;
                p-=t[i];
                i++;
            }
            else if(s>=1){
                s-=1;
                p+=t[j];
                j--;
            }
            else break;
            if(s>m) m=s;
            cout<<p<<" "<<i<<" "<<j<<" "<<s<<endl;
        }
        return m;
    }
};