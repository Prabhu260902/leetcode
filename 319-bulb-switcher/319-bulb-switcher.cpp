class Solution {
public:
    int bulbSwitch(int n) {
        int k=0;
        for(int i=1;i<=n;i++){
            if(k+(2*i)+1>=n) return i;
            else k+=(2*i)+1;
        }
        return 0;
    }
};