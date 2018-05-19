/*

Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

Example 1:

Input: "3+2*2"
Output: 7
Example 2:

Input: " 3/2 "
Output: 1
Example 3:

Input: " 3+5 / 2 "
Output: 5
Note:

You may assume that the given expression is always valid.
Do not use the eval built-in library function.
*/
class Solution {
public:
    int calculate(string s) {
        int digits = 0;
        vector<string> pm;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == ' ')
                continue;
            if(s[i] >= '0' && s[i] <= '9')
                digits = digits*10 + s[i]-'0';
                
            if(s[i] == '*' || s[i] == '/' || s[i] == '+' || s[i] == '-')
            {
                pm.push_back(to_string(digits));
                digits = 0;
                if(pm.size() > 1 && (pm[pm.size()-2] == "*" || pm[pm.size()-2] == "/"))
                {
                    int prev = stoi(pm[pm.size()-3]);
                    int cur = stoi(pm[pm.size()-1]);
                    if(pm[pm.size()-2] == "*")
                    {
                        //auto index = pm.size()-3;
                        pm.pop_back();pm.pop_back();pm.pop_back();
                        pm.push_back(to_string(prev*cur));
                    }
                    else if (pm[pm.size()-2] == "/")
                    {
                        pm.pop_back();pm.pop_back();pm.pop_back();
                        pm.push_back(to_string(prev/cur));
                    }                    
                }
                string op = ""; op.push_back(s[i]);
                pm.push_back(op);
            }
        }
        if(pm.empty()) return digits;
        if(pm.back() == "*")
        {
            pm.pop_back();
            int prev = stoi(pm.back());
            pm.pop_back();
            pm.push_back(to_string(prev*digits));
        }
        else if(pm.back() == "/")
        {
            pm.pop_back();
            int prev = stoi(pm.back());
            pm.pop_back();
            pm.push_back(to_string(prev/digits));
        }
        else
            pm.push_back(to_string(digits));
        
        int res = stoi(pm[0]);
        int i = 0;
        while(i < pm.size())
        {
            if(pm[i] == "+")
                res += stoi(pm[i+1]);
            if(pm[i] == "-")
                res -= stoi(pm[i+1]);
            i++;
        }
        return res;
       
        
    }
};


//Sol2: better. record sign and push digits into stack. if sign == '+', push +digits, '-' push -digits

class Solution {
public:
    int calculate(string s) {
        int res = 0;
        stack<int> st;
        char sign = '+';
        int digits = 0;
        for(int i = 0; i <= s.size(); i++)
        {
                      
            if(i == s.size() || s[i] == '+' || s[i] == '-' || s[i] =='*' || s[i] == '/')
            {
                if(sign == '+')
                    st.push(digits);
                if(sign == '-')
                    st.push(digits * -1);
                if(sign == '*')
                {
                    int prev = st.top(); st.pop();
                    st.push(prev*digits);
                }
                if(sign == '/')
                {
                    int prev = st.top(); st.pop();
                    st.push(prev/digits);
                }
                if(i != s.size())
                    sign = s[i];
                digits = 0;
            }
            if(s[i] >= '0' && s[i] <= '9')
                digits = digits*10 + s[i]-'0';
            if(s[i] == ' ')
                continue;             
        }
        
        
        while(!st.empty())
        {
            res += st.top();
            st.pop();
        }
        return res;
    }
};
