class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for(int i = 31; i >= 0; i--){
            ans |= (n & 1) << i;
            n=n>>1;
         }
        cout<<ans;
        return ans;
    }
};