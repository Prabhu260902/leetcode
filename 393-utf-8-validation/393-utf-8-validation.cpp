class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int k=0;
        for(auto i:data){
            if(k==0){
                if((i>>3) == 0b11110) k=3;
                else if((i>>4)==0b1110) k=2;
                else if((i>>5)==0b110) k=1;
                else if(i>>7) return false;
            }
            else{
                if((i>>6)!=0b10) return false;
                k--;
            }
        }
        if(k==0)
        return true;
        return false;
    }
};