/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. You may assume the dictionary does not contain duplicate words.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].
*/
// recurtion + memory_map
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if(m.count(s)) return m[s];
        
        unordered_set<string> sd;
        for(string word: wordDict)
            if (!sd.count(word)) sd.insert(word);
        
        vector<string> res;
        if(s.empty()) return res;
        if(sd.count(s)) res.push_back(s);
        for(int i = 1; i < s.size(); i++)
        {
            string word = s.substr(0, i);
            if (sd.count (word))
            {
                    vector<string> cur = combine(s.substr(0, i), wordBreak(s.substr(i), wordDict));
                    res.insert(res.end(), cur.begin(), cur.end());
             }
        }
        m[s] = res;
        return m[s];
    }
private:
    unordered_map<string, vector<string>> m;
    vector<string> combine(string cur, vector<string> prevs)
    {
        vector<string> res;
        for(string prev: prevs)
            res.push_back(cur+" "+prev);
        return res;
    }
};

