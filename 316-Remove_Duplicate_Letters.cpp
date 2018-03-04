/*
Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Example:
Given "bcabc"
Return "abc"

Given "cbacdcbc"
Return "acdb"
*/
// dict save the # of char for each char
// iterate s, for each char, if it is not in res and it is less than last char in res and the last char will appear later, then pop it
// add c and remove the # in dict by 1
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> dict(26, 0);
        for (char c: s)
            dict[c-'a']++;
        string res = "a";
        vector<bool> visited(26, false);
        for(char c: s)
        {
            if(visited[c-'a']) 
            {
                dict[c-'a']--;
                continue;
            }
            while(res.back() > c && dict[res.back()-'a'])
            {
                visited[res.back()-'a'] = false;
                res.pop_back();
            }
            res.push_back(c);
            visited[c-'a'] = true;
            dict[c-'a']--;
        }
        return res.substr(1);
    }
};
