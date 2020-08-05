Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

 

Example:

Input: 
board = [
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
words = ["oath","pea","eat","rain"]

Output: ["eat","oath"]

//Sol, trie (words list) + DFS.
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if (board.empty() || board[0].empty() || words.empty()) return res;
        Trie* root = new Trie();
        for (string& word : words) {
            root->Insert(word);
        }
        vector<vector<bool>> visited(board.size(),
                                     vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (root->root->children[board[i][j] - 'a']) {
                    Dfs(board, i, j, visited, root->root->children[board[i][j] - 'a'], res);
                }
            }
        }
        return res;
    }
private:
    struct TrieNode {
        TrieNode *children[26];
        string str;
        TrieNode() : str("") {
            for (auto &child : children) child = NULL;
        }
    };
    struct Trie {
        TrieNode* root;
        Trie() : root(new TrieNode()) {}
        void Insert(string word) {
            TrieNode* cur = root;
            for (char c : word) {
                if (cur->children[c - 'a'] == NULL) {
                    cur->children[c - 'a'] = new TrieNode();
                }
                cur = cur->children[c - 'a'];
            }
            cur->str = word;
        }
    };
    void Dfs(vector<vector<char>>& board, int i, int j, vector<vector<bool>>& visited, TrieNode* root, vector<string>& res) {
        if (root->str != "") {
            res.push_back(root->str);
            root->str.clear();
        }   
        visited[i][j] = true;
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (auto step : dirs) {
            int x = i + step[0];
            int y = j + step[1];
            if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size() &&
                !visited[x][y] && root->children[board[x][y] - 'a']) {
                Dfs(board, x, y, visited, root->children[board[x][y] - 'a'], res);
            }
        }
        visited[i][j] = false;
    }
};
