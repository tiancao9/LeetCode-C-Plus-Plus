Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Example 1:
Input: "aba"
Output: True
Example 2:
Input: "abca"
Output: True
Explanation: You could delete the character 'c'.
Note:
The string will only contain lowercase characters a-z. The maximum length of the string is 50000.

// If s[left++] != s[right--], check if s.substr(left+1, right - left) or s.substr(left, right-left) is a palindrome.
class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.size() - 1;  
        while (left < right) {
            if (s[left] != s[right]) {
                return IsPalindrome(left + 1, right, s)
                    || IsPalindrome(left, right - 1, s);
            }
            left++;
            right--;
        }
        return true;
    }
private:
    bool IsPalindrome(int left, int right, string s) {
        while (left < right) {
            if (s[left++] != s[right--])
                return false;
        }
        return true;
    }
};
