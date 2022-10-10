class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c=0;
        for(int i=digits.size()-1;i>=0;i--)
        {
            if(i==digits.size()-1 or c==1){
                digits[i]+=1;
                if(digits[i]>=10){
                    digits[i]-=10;
                    c=1;
                }
                else{
                    c=0;
                }
            }
        }
        if(c==1)
        {
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};