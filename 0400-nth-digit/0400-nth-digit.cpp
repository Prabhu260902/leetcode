class Solution {
public:
    int findNthDigit(int n) {
        if(n <= 9) return n;
        long long num = 9;
        long long num_count = 1;
        while(n > num * num_count){
            n -= num * num_count;
            num *= 10;
            num_count++;
        }
        int x = pow(10,num_count-1) + (n-1) / num_count;
        int k = num_count - (n-1)%num_count;
        int r ;
        // cout << x << " " << k << endl;
        while(k--){
            r = x % 10;
            x = x/10;
            cout << r << " " << x << endl;
        }
        return r;
    }
};