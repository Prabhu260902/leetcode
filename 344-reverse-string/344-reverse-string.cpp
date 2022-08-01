class Solution {
public:
    void reverseString(vector<char>& s) {
        int i=0,e=s.size()-1;
        while(i<=e){
        swap(s[i++],s[e--]); }
        
    }
};