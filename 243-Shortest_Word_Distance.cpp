/*
Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

Example:
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Input: word1 = “coding”, word2 = “practice”
Output: 3
Input: word1 = "makes", word2 = "coding"
Output: 1
Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
*/

// Use 2 vector to record the index of word1 and word2
class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        vector<int> w1_index;
        vector<int> w2_index;
        
        int d = INT_MAX;
        for (int i = 0; i < words.size(); i++){
            if (words[i] == word1)
                w1_index.push_back(i);
            else if (words[i] == word2)
                w2_index.push_back(i);
            if(!w1_index.empty() && !w2_index.empty() && abs(w1_index.back()-w2_index.back()) < d)
                d = abs(w1_index.back() - w2_index.back());
        }
        
        return d;
    }
};
