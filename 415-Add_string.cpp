Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.

// string manipulation
class Solution {
public:
    string addStrings(string num1, string num2) {
        string res;
        if (num1.empty()) return num2;
        if (num2.empty()) return num1;
        int m = num1.size() - 1;
        int n = num2.size() - 1;
        int carry = 0;
        while (m >= 0 || n >= 0) {
            int sum = carry;
            if (m >= 0) sum += num1[m--] - '0';
            if (n >= 0) sum += num2[n--] - '0';
            res.push_back((sum) % 10 + '0');
            carry = sum / 10;
        }
        if (carry)
            res.push_back('1');
        reverse(res.begin(), res.end());
        return res;
    }
};
