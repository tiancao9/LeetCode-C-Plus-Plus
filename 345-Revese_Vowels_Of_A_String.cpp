/*
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".
*/
// Sol1: extra string vowels, Time: O(n), Space: O(n)
class Solution {
public:
    string reverseVowels(string s) {
        string vowels = "";
        for(char c: s)
        {
            if (c == 'a' || c== 'e' || c == 'o' || c == 'i' || c == 'u' || c == 'A' || c== 'E' || c == 'O' || c == 'I' || c == 'U')
                vowels.push_back(c);
        }
        string res = "";
        for (char c: s)
        {
            if (c == 'a' || c== 'e' || c == 'o' || c == 'i' || c == 'u' || c == 'A' || c== 'E' || c == 'O' || c == 'I' || c == 'U')
            {
                res.push_back(vowels.back());
                vowels.pop_back();
            }
            else
                res.push_back(c);
        }
        return res;
    }
};

// Sol2: 2 pointer Time: O(n), Space: O(1)
class Solution {
public:
    string reverseVowels(string s) {
        int left = 0;
        int right = s.size()-1;
        unordered_set<char> set = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        while (left < right)
        {
            while(left < s.size() && !set.count(s[left]))
                left++;
            while(right >= 0 && !set.count(s[right]))
                right--;
            if(left < right)
            {
                swap(s[left], s[right]);
                left ++;
                right --;
            }
        }
        return s;
    }
};
