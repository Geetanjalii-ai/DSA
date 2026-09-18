class Solution {
public:
    int evalRPN(vector<string>& s) {

        stack<int> st;
        for(int i=0;i<s.size();i++)
        {
            if(isdigit(s[i][0]) || (s[i][0]=='-' && s[i].size()>1))
            {
                st.push(stoll(s[i]));
            }
            else
            {
                int a=st.top();
                st.pop();

                int b=st.top();
                st.pop();

                int eval;

                if(s[i]=="+")
                {
                    eval=(a+b);
                }
                else if(s[i]=="*")
                {
                    eval=(a*b);
                }
                else if(s[i]=="-")
                {
                    eval=(b-a);
                }
                else
                {
                    eval=(b/a);
                }
                st.push(eval);
            }
        }

        return st.top();
        
    }
};
