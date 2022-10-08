class Solution {
public:
    int fib(int n) {
        if(n < 2){
            return n;
        }
        vector<int> vals = {0, 1};
        
        int i = 2;
        int sum = 1;
        while(i <= n){
            sum = vals[i-1] + vals[i-2];
            vals.push_back(sum);
            i++;
        }
        
        return sum;
    }
};