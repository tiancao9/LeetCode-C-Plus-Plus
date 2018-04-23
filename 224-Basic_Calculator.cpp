/*
Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

You may assume that the given expression is always valid.

Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23
*/
// calculate whenever a integer comes, push back the result
// for parenthesis, when we get ')', get the pre int, remove the '(' and calculate the result, push back
class Solution {
public:
    int calculate(string s) {
        stack<string> st;
        string op;
        int cur_int, prev_int;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '-')
                st.push("-");
            else if (s[i] == '+')
                st.push("+");
            else if(s[i] == '(')
                st.push("(");
            else if (s[i] >= '0' && s[i] <= '9')
            {
                string cur = "";
                while(s[i] >= '0' && s[i] <= '9')
                {
                    cur.push_back(s[i]);
                    i++;
                }
                i--;
                if(!st.empty() && st.top() != "(")
                {
                    cur_int = stoi(cur);
                    op = st.top(); st.pop();
                    prev_int = stoi(st.top()); st.pop();
                    if(op == "-")
                        st.push(to_string(prev_int - cur_int));
                    else if (op == "+")
                        st.push(to_string(prev_int + cur_int));
                }
                else
                    st.push(cur);
            }
            else if(s[i] == ')')
            {
                string inside = st.top(); st.pop();
                st.pop(); // remove "("
                st.push(inside);
                if(st.size() != 1)
                {
                    cur_int = stoi(st.top()); st.pop();
                    op = st.top(); st.pop();
                    prev_int = stoi(st.top()); st.pop();
                    if(op == "-")
                        st.push(to_string(prev_int - cur_int));
                    else if (op == "+")
                        st.push(to_string(prev_int + cur_int));
                }
            }
        }
        
       
        return stoi(st.top());
    }
    
};
