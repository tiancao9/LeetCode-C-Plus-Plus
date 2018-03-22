/*
Given two strings s and t which consist of only lowercase letters.

String t is generated by random shuffling string s and then add one more letter at a random position.

Find the letter that was added in t.

Example:

Input:
s = "abcd"
t = "abcde"

Output:
e

Explanation:
'e' is the letter that was added.
*/
class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> s1;
        for(char c: s)
            s1[c]++;
        for(char c: t)
        {
            if(!s1.count(c) || s1[c] == 0)
                return c;
            else 
                s1[c]--;
        }
    }
};