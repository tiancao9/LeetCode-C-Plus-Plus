/*
There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of non-empty words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.

Example 1:

Input:
[
  "wrt",
  "wrf",
  "er",
  "ett",
  "rftt"
]

Output: "wertf"
Example 2:

Input:
[
  "z",
  "x"
]

Output: "zx"
Example 3:

Input:
[
  "z",
  "x",
  "z"
] 

Output: "" 

Explanation: The order is invalid, so return "".
Note:

You may assume all letters are in lowercase.
You may assume that if a is a prefix of b, then a must appear before b in the given dictionary.
If the order is invalid, return an empty string.
There may be multiple valid order of letters, return any one of them is fine.

*/

// topology_sorting
class Solution {
public:
    string alienOrder(vector<string>& words) {
        
        if(words.empty()) return "";
        vector<vector<char>> graph(26, vector<char>());
        unordered_map<char, int> in_degree;
        
        if(!construct_graph(graph, in_degree, words))
            return "";
        return topology_sort(graph, in_degree);
        
    }
    
private:
    bool construct_graph(vector<vector<char>>& graph, unordered_map<char, int>& in_degree, vector<string>& words)
    {
        for(string word: words)
            for(char c: word)
                in_degree[c] = 0;
        
        for(int i = 1; i < words.size(); i++)
        {
            string prev = words[i-1];
            string cur = words[i];
            int j = 0;
            while(j < prev.size() && j < cur.size() && prev[j] == cur[j]) j++;
            if(j == cur.size() && j < prev.size()) return false;
            if(j < prev.size() && j < cur.size())
            {
                in_degree[cur[j]]++;
                graph[prev[j]-'a'].push_back(cur[j]);
            }
        }
        
        return true;
    }
    string topology_sort(vector<vector<char>>& graph, unordered_map<char, int>& in_degree)
    {
        string res;
        queue<char> q;
        for(auto ind: in_degree)
            if(!ind.second)
                q.push(ind.first);
        while(!q.empty())
        {
            char cur = q.front(); q.pop();
            res.push_back(cur);
            for(char c: graph[cur-'a'])
            {
                in_degree[c]--;
                if(!in_degree[c])
                    q.push(c);
            }
        }
        
        for(auto ind: in_degree)
            if(ind.second)
                return "";
        return res;
    }
};
