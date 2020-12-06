Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.
Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.

// Sol, select the smallest num.size() - k digits.
class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size() - k;
        string res = "";
        int i = 0;
        while (i < num.size() && n > 0) {
            unordered_map<int, int> m;
            int min_v = INT_MAX;
            while (num.size() - i >= n) {
                if (num[i] < min_v) {
                    min_v = num[i];
                    m[num[i]] = i;
                }
                i++;
            }
            res.push_back(num[m[min_v]]);
            i = m[min_v] + 1;
            n--;
        }
        if (res == "") return "0";
        i = 0;
        while (i < res.size() && res[i] == '0') {
            i++;
        }
        if (i == res.size()) return "0";
        return res.substr(i);
    }
}; 
