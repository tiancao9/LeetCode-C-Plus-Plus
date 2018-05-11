/*
Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

Note: The input string may contain letters other than the parentheses ( and ).

Examples:
"()())()" -> ["()()()", "(())()"]
"(a)())()" -> ["(a)()()", "(a())()"]
")(" -> [""]
*/
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        //scan s, when '(' > ')', stop, since it will not deliver a solution
        int left = 0;
        int right = 0;
        vector<string> res;
        for(int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                left++;
            else if(s[i] == ')')
            {
                if (left > 0)
                    left--;
                else
                    right++;
            }
        }
        remove_dfs(0,left,right,0,s,res);
        return res;
    }
    void remove_dfs(int begin, int left, int right, int open, string s, vector<string>& res)
    {
        for(int i = begin; i < s.size() && open >= 0; i++)
        {
            if(s[i] == '(')
            {
                if (left > 0 && (i == 0 || s[i-1] != '('))
                    remove_dfs(i, left-1, right, open, s.substr(0,i) + s.substr(i+1), res);
                open++;
            }
            else if (s[i] == ')')
            {
                if(right > 0 && (i == 0 || s[i-1] != ')'))
                    remove_dfs(i, left, right-1, open, s.substr(0,i) + s.substr(i+1), res);
                open--;
            }
        }
        if(left == 0 && right == 0 && open == 0)
            res.push_back(s);
    }
};
