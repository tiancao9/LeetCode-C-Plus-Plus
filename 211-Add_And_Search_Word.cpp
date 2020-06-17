Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

Example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.

// TrieNode
class WordDictionary {
public:
    struct TrieNode {
        bool IsWord;
        TrieNode *children[26];
        TrieNode() : IsWord(false) {
            for (auto& child : children) {
                child = nullptr;
            }
        }
    };
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* cur_root = root;
        for (char c : word) {
            if (!cur_root->children[c - 'a']) {
                cur_root->children[c - 'a'] = new TrieNode();
            }
            cur_root = cur_root->children[c - 'a'];
        }
        cur_root->IsWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return SearchWord(word, root, 0);
    }

private:
  TrieNode* root;
  bool SearchWord(string& word, TrieNode* root, int index) {
      if (index == word.size()) return root->IsWord;
      if (word[index] == '.') {
          for (int i = 0; i < 26; i++) {
              if (root->children[i] && SearchWord(word, root->children[i], index+1))
                  return true;
          }
          return false;
      }
      return root->children[word[index] - 'a'] && SearchWord(word, root->children[word[index] - 'a'], index+1);
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
