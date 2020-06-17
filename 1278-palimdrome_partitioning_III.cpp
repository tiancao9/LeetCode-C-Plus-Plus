You are given a string s containing lowercase letters and an integer k. You need to :

First, change some characters of s to other lowercase English letters.
Then divide s into k non-empty disjoint substrings such that each substring is palindrome.
Return the minimal number of characters that you need to change to divide the string.

 

Example 1:

Input: s = "abc", k = 2
Output: 1
Explanation: You can split the string into "ab" and "c", and change 1 character in "ab" to make it palindrome.
Example 2:

Input: s = "aabbc", k = 3
Output: 0
Explanation: You can split the string into "aa", "bb" and "c", all of them are palindrome.
Example 3:

Input: s = "leetcode", k = 8
Output: 0
 

Constraints:

1 <= k <= s.length <= 100.
s only contains lowercase English letters.

// DP
class Solution {
public:
    int palindromePartition(string s, int k) {
        // dp[i][k] = min(dp[j][k-1] + cost[j+1][i]), j from 0 to i-1.
        // cost[i][j] is minimum changes that make s.substr(i, j-i+1) as a palindrome.
        // result is dp[n-1][k], n = s.size().
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(k+1, INT_MAX / 2));
        vector<vector<int>> cost = GetCost(s);
        for (int i = 0; i < n; i++) {
            dp[i][1] = cost[0][i];
            for (int cuts = 2; cuts <= k; cuts++) {
                for (int j = 0; j < i; j++) {
                    dp[i][cuts] = min((dp[j][cuts-1] + cost[j+1][i]), dp[i][cuts]);
                }
            }
        }
            return dp[n-1][k];
    }
private:
    vector<vector<int>> GetCost(const string& s) {
        int n = s.size();
        vector<vector<int>> cost(n, vector<int>(n, 0));
        // for length from 2 to n, cost[i][j] = s[i] == s[j] + cost[i+1][j-1];
        for (int l = 2; l <= n; l++) {
            for (int i = 0, j = l-1; j < n; i++, j++) {
                cost[i][j] = (s[i] != s[j]) + cost[i+1][j-1];
            }
        }
        return cost;
    }
};
