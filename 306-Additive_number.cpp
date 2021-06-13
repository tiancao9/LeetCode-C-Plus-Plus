Additive number is a string whose digits can form additive sequence.

A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.

Given a string containing only digits '0'-'9', write a function to determine if it's an additive number.

Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.

 

Example 1:

Input: "112358"
Output: true
Explanation: The digits can form an additive sequence: 1, 1, 2, 3, 5, 8. 
             1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
Example 2:

Input: "199100199"
Output: true
Explanation: The additive sequence is: 1, 99, 100, 199. 
             1 + 99 = 100, 99 + 100 = 199
 

Constraints:

num consists only of digits '0'-'9'.
1 <= num.length <= 35
Follow up:
How would you handle overflow for very large input integers?

// Sol, just iterate and get nums1, nums2 and check the sum.
class Solution {
public:
    bool isAdditiveNumber(string num) {
        for (int i = 1; i <= num.size() / 2; i++) {
            for (int j = 1; j <= (num.size() - i) / 2; j++) {
                if (Check(num.substr(0, i), num.substr(i, j), num.substr(i + j))) {
                    return true;
                }
            }
        }
        return false;
    }
private:
    bool Check(const string& num1, const string& num2, const string& num) {
        if ((num1.size() > 1 && num1[0] == '0') || (num2.size() > 1 && num2[0] == '0')) {
            return false;
        }
        string sum = Sum(num1, num2);
        if (sum == num) return true;
        if (sum.size() > num.size() || num.substr(0, sum.size()) != sum) return false;
        return Check(num2, sum, num.substr(sum.size()));
    }

    string Sum(const string& nums1, const string& nums2) {
        int i = nums1.size() - 1;
        int j = nums2.size() - 1;
        int carry = 0;
        int sum = 0;
        string res;
        while (i >= 0 || j >= 0) {
            sum += carry;
            if (i >= 0) sum += nums1[i--] - '0';
            if (j >= 0) sum += nums2[j--] - '0';
            carry = sum / 10;
            res.push_back(sum % 10 + '0');
            sum = 0;
        }
        if (carry) res.push_back(carry + '0');
        reverse(res.begin(), res.end());
        return res;
    }
};
