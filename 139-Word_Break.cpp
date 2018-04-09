/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words. You may assume the dictionary does not contain duplicate words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/

//DP, DP[i] == true if DP[j] == true and s.substr(j+1, i-j) in wordDict 
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        set<string> wordset;
        for(int i = 0; i < wordDict.size(); i++)
            wordset.emplace(wordDict[i]);
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        
        for(int i = 0; i < s.size(); i++)
        {
            for(int j = i; j >= 0; j--)
            {
                if(dp[j] && wordset.count(s.substr(j,i-j+1)))
                {
                    dp[i+1] = true;
                    break;
                }
            }
        }
        
        
        return dp[s.size()];        
    }
    
};
