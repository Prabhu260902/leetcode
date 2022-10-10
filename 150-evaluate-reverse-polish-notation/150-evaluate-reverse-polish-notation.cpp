class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long>s;
        for(auto i:tokens){
            if(i=="+")
            {
                long b=s.top();
                s.pop();
                long a=s.top();
                s.pop();
                s.push(a+b);
            }
            else if(i=="-")
            {
                long b=s.top();
                s.pop();
                long a=s.top();
                s.pop();
                s.push(a-b);
            }
            else if(i=="*")
            {
                long b=s.top();
                s.pop();
                long a=s.top();
                s.pop();
                s.push(a*b);
            }
            else if(i=="/")
            {
                long b=s.top();
                s.pop();
                long a=s.top();
                s.pop();
                s.push(a/b);
            }
            else{
                s.push(stoi(i));
            }
        }
        return s.top();
    }
};