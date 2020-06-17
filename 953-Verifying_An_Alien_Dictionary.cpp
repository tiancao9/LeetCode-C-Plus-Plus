In an alien language, surprisingly they also use english lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographicaly in this alien language.

 

Example 1:

Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.
Example 2:

Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.
Example 3:

Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: false
Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).
 

Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 20
order.length == 26
All characters in words[i] and order are English lowercase letters.

// Build map with m[char]=index.
// Compare word one by one, if the word1[j] < word2[j], compare next, if  word1[j] == word2[j], j++, 
// else, return false.
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> m;
        for (int i = 0; i < order.size(); i++) {
            m[order[i]] = i;
        }
        for (int i = 0; i < words.size() - 1; i++) {
            int j = 0;
            while (i < words.size() - 1 && j < words[i].size() && j < words[i+1].size()) {
                if (m[words[i][j]] < m[words[i+1][j]]) {
                    i++;
                } else if (m[words[i][j]] > m[words[i+1][j]]) {
                    return false;
                } else {
                    j++;
                }
            }
            if (i < words.size() - 1 && words[i].size() > words[i+1].size() &&
                words[i].substr(0, j) == words[i+1]) {
                return false;
            }
        }
        return true;
    }
}; 
