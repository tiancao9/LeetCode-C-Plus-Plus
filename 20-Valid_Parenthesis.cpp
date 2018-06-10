/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true

*/
class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        char prev;
        for(char c: s)
        {
            if(st.empty() || c == '(' || c == '{' || c == '[')
                st.push(c);
            else{
                prev = st.top();             
                if((c == ')' && prev == '(') || (c == ']' && prev == '[') || (c == '}' && prev == '{'))
                    st.pop();
                else
                    return false;
            }                      
            
        }
        if(!st.empty()) return false;
        return true;
    }
};
