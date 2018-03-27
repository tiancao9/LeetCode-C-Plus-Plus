/*
Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        vector<int> data;
        int carry = 1;
        for(int i = digits.size()-1; i >= 0; i--)
        {
            int cur = carry + digits[i];
            data.push_back(cur % 10);
            carry = cur / 10;
        }
        if (carry)
            data.push_back(carry);
        reverse(data.begin(), data.end());
        return data;
    }
};
