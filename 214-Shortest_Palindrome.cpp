/*
Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.

For example:

Given "aacecaaa", return "aaacecaaa".

Given "abcd", return "dcbabcd".
*/
class Solution {
public:
    string shortestPalindrome(string s) {
        if(s == "" || s.size() == 0 || check_palindrome(s)) return s;
        string res = "";
        //center at left half
        vector<int> index_l;
        for(int i = 1; i < s.size(); i++)
            if(s[i] == s[0])
                index_l.push_back(i);
        //for each index_l[i], check if s.substr(0, index_l[i]+1) is palindrome
        for(int i = index_l.size() - 1; i >= 0; i--)
        {
            if(check_palindrome(s.substr(0, index_l[i]+1)))
            {
                string pad = s.substr(index_l[i]+1, s.size()-1-index_l[i]);
                reverse(pad.begin(), pad.end());
                res = pad + s;
                break;
            }
        }
        //center at right half
        vector<int> index_r;
        for(int i = s.size()-2; i >= 0; i--)
            if(s[i] == s[s.size()-1])
                index_l.push_back(i);
        //for each index_r[i], check if s.substr(index_r[i],s.size()-index_r[i]) is palindrome
        for(int i = index_r.size() - 1; i >= 0; i--)
        {
            if(check_palindrome(s.substr(index_r[i],s.size()-index_r[i])))
            {
                string pad = s.substr(0,index_r[i]);
                reverse(pad.begin(), pad.end());
                if(pad.size() + s.size() < res.size())
                    res = s+pad;
                break;
            }
        }
        if(res == "")
        {
            string pad = s.substr(1, s.size()-1);
            reverse(pad.begin(), pad.end());
            res = pad + s;
        }
        return res;
    }
private:
    bool check_palindrome(string s)
    {
        if(s.empty()) return true;
        int left = 0;
        int right = s.size() - 1;
        while(left < right)
        {
            if(s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};
