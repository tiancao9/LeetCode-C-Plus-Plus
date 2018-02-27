/*
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
*/
class Solution {
public:
    string reverseWords(string s) {
        if(s.empty()) return s;
        s += " ";
        int right = 0;
        int left = 0;
        string res;
        while(right < s.size())
        {
            while(s[right] != ' ')
                right++;
            string cur = s.substr(left, right-left);//c++ substr(not a pointer, len)
            reverse(cur.begin(), cur.end());//reverse func does not return a string
            res += cur;
            res += " ";
            left = right + 1;
            right++;
        }
        res.pop_back();
        return res;
    }
};
