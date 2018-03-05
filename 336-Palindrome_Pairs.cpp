/*
Given a list of unique words, find all pairs of distinct indices (i, j) in the given list, so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.

Example 1:
Given words = ["bat", "tab", "cat"]
Return [[0, 1], [1, 0]]
The palindromes are ["battab", "tabbat"]
Example 2:
Given words = ["abcd", "dcba", "lls", "s", "sssll"]
Return [[0, 1], [1, 0], [3, 2], [2, 4]]
The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]
*/

class Solution {
    //Time: O(n*k^2) Space: O(n)
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> m;
        for(int i = 0; i < words.size(); i++)
            m[words[i]] = i;
        vector<vector<int>> res;
        for(int i = 0; i < words.size(); i++)
        {
            string temp = words[i];
            reverse(temp.begin(), temp.end());
            if(m.count(temp) && m[temp] != i) res.push_back({i, m[temp]});
            for(int j = 0; j < words[i].size(); j++)
            {
                string temp2 = ""; 
                if(j == 0)
                    temp = "";
                else
                {
                    temp = words[i].substr(0,j);
                    reverse(temp.begin(), temp.end());
                    temp2 = words[i].substr(words[i].size()-j);
                    reverse(temp2.begin(), temp2.end());
                }
                if(m.count(temp) && is_palindrome(words[i].substr(j)))
                    res.push_back({i, m[temp]});
                if(m.count(temp2) && is_palindrome(words[i].substr(0,words[i].size()-j)))
                    res.push_back({m[temp2], i});
            }
        }
        return res;
    }
private:
    bool is_palindrome(string s)
    {
        int left = 0;
        int right = s.size()-1;
        while(left < right)
        {
            if(s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};
