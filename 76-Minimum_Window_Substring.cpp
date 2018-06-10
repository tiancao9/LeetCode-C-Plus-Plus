/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
Note:

If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
*/
// use map to record char and # for t
// 2 pointer, begin and end, if s[end] in t and map[s[end]] > 0, count--, end++
// when count == 0, means the substr has all the char in t
// if s[begin] not in t, begin++, if s[begin] in t and map[s[begin]] < 0, begin++, else, count++, begin++
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> map;
        for (char c: t)
            map[c]++;
        int begin = 0;
        int end = 0;
        string res = "";
        int count = t.size();
        int l = INT_MAX;
        while(end < s.size())
        {
            while(count > 0 && end < s.size())
            {
                 if (map.count(s[end]))
                 {                    
                     if(map[s[end]] > 0)
                         count--;
                     map[s[end]]--;
                 }
                end++;
                if(!count) break;
            }
            while(count == 0)
            {
                if(end - begin < l) 
                {
                    res = s.substr(begin, end-begin);
                    l = end-begin;
                }
                if(!map.count(s[begin]))
                    begin++;
                else if(map[s[begin]] < 0)
                    map[s[begin++]]++;
                else if(map[s[begin]] == 0)
                {
                    count++;
                    map[s[begin++]]++;
                }
            }
                            
        }
        return res;
    }
};


// Concise sol
class Solution {
public:
    string minWindow(string s, string t) {
       
        vector<int> m(128, 0);
        for(char c: t)
            m[c]++;
        int begin = 0;
        int end = 0;
        int count = t.size();
        int length = INT_MAX;
        string res;
        while(end < s.size())
        {
            if(m[s[end++]]-- > 0) count--;
            while(count == 0)
            {
                if(end-begin < length){
                    res = s.substr(begin, end-begin);
                    length = res.size();
                }
                if(m[s[begin++]]++ == 0) count++;
            }
        }
        return res;
    }
};
