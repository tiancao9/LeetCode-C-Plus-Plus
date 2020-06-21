Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
An empty string is also valid.
Example 1:
Input: "()"
Output: True
Example 2:
Input: "(*)"
Output: True
Example 3:
Input: "(*))"
Output: True
Note:
The string size will be in the range [1, 100].

// 2 stacks, left & star, need to record the index: make sure the remaining
// lefts can be cancled (i.e. on the left of) with the remaining stars.
class Solution {
public:
    bool checkValidString(string s) {
        stack<int> left, star;
        int i = 0;
        for (char c : s) {
            if (c == '(') {
                left.push(i);
            } else if (c == '*') {
                star.push(i);
            } else if (c == ')') {
                if (!left.empty()) {
                    left.pop();
                } else if (!star.empty()) {
                    star.pop();
                } else {
                    return false;
                }
            }
            i++;
        }
        while (!left.empty()) {
            int cur_left = left.top();
            if (star.empty()) return false;
            int cur_star = star.top();
            if (cur_left > cur_star) return false;
            left.pop();
            star.pop();
        }
        if (!left.empty()) return false;
        return true;
    }
};
