/*
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
*/
//Time: O(n) Space: O(1)
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<int, int> m;
        for(char c: magazine)
            m[c]++;
        for(char c: ransomNote)
        {
            if(m.count(c) && m[c] > 0)
                m[c]--;
            else
                return false;
        }
        return true;           
            
    }
};
