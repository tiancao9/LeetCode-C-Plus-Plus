/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/
//DFS, add '(' when left < n, add ')' when right < left < n, append cur when left == n && right == n 
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        int nleft = 0;
        int nright = 0;
        string cur;
        vector<string> all;
        
        deeper(0,0,cur,all,n);
        
        return all;
    }
    
private:
    void deeper (int nleft, int nright, string &cur, vector<string> &all, int n)
    {
        if (nleft == n && nright == n)
        {
            all.push_back(cur);
            return;
        }
        
        if(nleft < n)
        {
            cur.push_back('(');
            deeper(nleft+1, nright, cur, all, n);
            cur.pop_back();
        }
        
        if(nright < nleft)
        {
            cur.push_back(')');
            deeper(nleft, nright+1, cur, all, n);
            cur.pop_back();
        }
        
        
    }
};
