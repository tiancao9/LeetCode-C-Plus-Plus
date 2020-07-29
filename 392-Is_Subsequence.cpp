Given a string s and a string t, check if s is subsequence of t.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).

Follow up:
If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T has its subsequence. In this scenario, how would you change your code?

// Sol1, basic char search, T = t.size(), S = s.size(), O(T*S).
class Solution {
public:
    bool isSubsequence(string s, string t) {
        size_t pos = 0;
        for (char c : s) {
            pos = t.find(c, pos);
            if (pos == std::string::npos) {
                return false;
            }
            pos++;
        }
        return true;
    }
};

// Sol2, for the follow up question. Use hashmap to store all the indexes mapped to each char, and binary search for S's chars.
// O(Slog(T)).
class Solution {
public:
    bool isSubsequence(string s, string t) {
        unordered_map<char, vector<int>> m;
        for (int i = 0; i < t.size(); i++) {
            m[t[i]].push_back(i);
        }
        int pre = -1;
        for (char c : s) {
            if (m.count(c) == 0) return false;
            auto pos = upper_bound(m[c].begin(), m[c].end(), pre);
            if (pos == m[c].end()) return false;
            pre = *pos;
        }
        return true;
    }
};
