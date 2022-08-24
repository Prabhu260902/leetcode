class Solution {
public:
    bool isPowerOfThree(int n) {
        for(int i=0;;i++)
        {
            if(pow(3,i)==n) return(true);
            else if(pow(3,i)>n) return(false);
        }
        
    }
};