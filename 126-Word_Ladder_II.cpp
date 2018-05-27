/*
Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:

Only one letter can be changed at a time
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
Note:

Return an empty list if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output:
[
  ["hit","hot","dot","dog","cog"],
  ["hit","hot","lot","log","cog"]
]
Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: []

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
*/
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s;
        for(string word: wordList) s.insert(word);
        queue<vector<string>> q;
        vector<string> temp = {beginWord};
        q.push(temp);
        vector<string> visited;
        vector<vector<string>> res;
        
        if(!s.count(endWord)) return res;
        bfs(s, q, visited, res, endWord);
        return res;
    }
    
private:
    void bfs(unordered_set<string>& s,
             queue<vector<string>>& q,
             vector<string>& visited,
             vector<vector<string>>& res,
             string endWord
             )
    {
        bool last_level = false; // track if this level is last level that contain endWord
        int n = q.size();
        for(int i = 0; i < n; i++)
        {
            vector<string> cur_v = q.front(); q.pop();
            string cur_s = cur_v.back();
            for(int j = 0; j < cur_s.size(); j++)
                for(int k = 0; k < 26; k++)
                {
                    if(k+'a' != cur_s[j])
                    {
                        string next = cur_s;
                        next[j] = k+'a';
                        if(next == endWord) last_level = true;
                        if(s.count(next)) 
                        {
                            cur_v.push_back(next); q.push(cur_v);
                            if(next == endWord) res.push_back(cur_v);
                            cur_v.pop_back();
                            visited.push_back(next);
                        }
                       
                    }
                }
        }
        
        if(last_level) return;
        for(string word: visited) s.erase(word);
        visited.clear();
        if(!q.empty()) bfs(s, q, visited, res, endWord);
    }
    
};
