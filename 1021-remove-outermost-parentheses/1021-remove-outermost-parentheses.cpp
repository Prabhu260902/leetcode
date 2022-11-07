class Solution {
public:
    string removeOuterParentheses(string s) {
	string ans="";
	stack<string>st;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='(') st.push("(");
		else
		{
			st.top()=st.top()+")";
			if(st.size()==1) st.pop();
			else if(st.size()==2)
			{
				ans+=st.top();
				st.pop();
			}
			else
			{
				string k=st.top();
				st.pop();
				st.top()=st.top()+k;
			}
		}
	}
	return ans;
    }
};