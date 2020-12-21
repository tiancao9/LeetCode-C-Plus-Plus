Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

 

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
Example 4:

Input: s = "adceb", p = "*a*b"
Output: true
Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
Example 5:

Input: s = "acdcb", p = "a*c?b"
Output: false
 

Constraints:

0 <= s.length, p.length <= 2000
s contains only lowercase English letters.
p contains only lowercase English letters, '?' or '*'.

// Recursion + reduce. 
class Solution {
public:
    bool isMatch(string s, string p) {
        return helper(s, p) > 1;
    }
private:
    int helper(string s, string p) {
        if (s.empty() && !p.empty()) {
            int i = 0;
            while (i < p.size() && p[i] == '*') {
                i++;
            }
            if (i < p.size()) return 0;
        }
        if (s.empty() && p.empty()) return 2;
        if (!s.empty() && p.empty()) return 1;
        if (p[0] == '*') {
            int j = 0;
            while (p[j] == '*') j++;
            j--;
            for (int i = 0; i <= s.size(); i++) {
                int res = helper(s.substr(i), p.substr(j+1));
                // reduce, res == 0, when s finish matching but p still has chars != *, no need to continue.
                if (res == 0 || res == 2) return res;
            }
            return 1;
        } else if (p[0] == '?') {
            return helper(s.substr(1), p.substr(1));
        } else {
            if (s[0] == p[0]) return helper(s.substr(1), p.substr(1));
            return 1;
        }
        
    }
};
