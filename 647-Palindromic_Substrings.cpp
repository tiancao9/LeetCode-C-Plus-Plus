/*
Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:
Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:
Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
*/
class Solution {
public:
    int countSubstrings(string s) {
        if(s.empty()) return 0;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int res = 0;
        //get substr status, put true in dp if the substr is palindrome
        for (int i = 0; i < s.size(); i++) //end from pos i
        {
            for (int j = i; j >= 0; j--) //begin from pos j
            {
                if (i == j || (s[i] == s[j] && i == j+1) || (j < i-1 && s[i] == s[j] && dp[j+1][i-1]))
                {
                    res += 1;
                    dp[j][i] = true;
                }
            }
        }
        return res;
    }
};
