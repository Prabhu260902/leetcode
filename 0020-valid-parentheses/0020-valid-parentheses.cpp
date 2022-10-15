class Solution {
public:
    bool isValid(string ve) {
        stack<int>st;
        int n,a,c=0,m=0;
        for(int i=0;i<ve.length();i++)
        {
            if(ve[i]=='(' || ve[i]=='{' || ve[i]=='[')
            {
                st.push(ve[i]);
            } 
            else
            {
                if(ve[i]==')' && !st.empty())
                {
                    if(st.top()=='(')
                    {
                        st.pop();
                    }  
                    else
                {
                    st.push(ve[i]);
                }
                    
                }
                else if(ve[i]=='}' && !st.empty())
                {
                    if(st.top()=='{')
                    {
                        st.pop();
                    }   
                    else
                {
                    st.push(ve[i]);
                }
                }
                else if(ve[i]==']' && !st.empty())
                {
                    if(st.top()=='[')
                    {
                        st.pop();
                    }
                    else
                {
                    st.push(ve[i]);
                }
                }
                else
                {
                    st.push(ve[i]);
                }
            }
        }
        cout<<st.size();
        if(st.empty()) 
        {
             return(true);
        }    
           
        else return(false);
        }
    };