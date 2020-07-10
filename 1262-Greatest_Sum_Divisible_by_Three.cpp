Given an array nums of integers, we need to find the maximum possible sum of elements of the array such that it is divisible by three.

 

Example 1:

Input: nums = [3,6,5,1,8]
Output: 18
Explanation: Pick numbers 3, 6, 1 and 8 their sum is 18 (maximum sum divisible by 3).
Example 2:

Input: nums = [4]
Output: 0
Explanation: Since 4 is not divisible by 3, do not pick any number.
Example 3:

Input: nums = [1,2,3,4,4]
Output: 12
Explanation: Pick numbers 1, 3, 4 and 4 their sum is 12 (maximum sum divisible by 3).
 

Constraints:

1 <= nums.length <= 4 * 10^4
1 <= nums[i] <= 10^4

// Hashmap/vector with min heap.
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> m;
        int sum = 0;
        for (int num : nums) {
            m[num % 3].push(num);
            sum += num;
        }
        int remain = sum % 3;
        if (remain == 0) {
            return sum;
        } else if (remain == 1) {
            int op1, op2;
            if (m.count(1) && m.count(2) && m[2].size() >= 2) {
                op1 = m[1].top();
                op2 = m[2].top(); m[2].pop();
                op2 += m[2].top();
                if (op1 > op2) return sum - op2;
                return sum - op1;
            } else if (m.count(1)) {
                return sum - m[1].top();
            } else if (m.count(2) && m[2].size() >= 2) {
                sum -= m[2].top(); m[2].pop();
                return sum - m[2].top();
            } else {
                return 0;
            }
        } else {
            int op1, op2;
            if (m.count(1) && m[1].size() >= 2 && m.count(2)) {
                op1 = m[1].top(); m[1].pop();
                op1 += m[1].top();
                op2 = m[2].top();
                if (op1 > op2) return sum - op2;
                return sum - op1;
            } else if (m.count(2)) {
                return sum - m[2].top();
            } else if (m.count(1) && m[1].size() >= 2) {
                sum -= m[1].top(); m[1].pop();
                return sum - m[1].top();
            } else {
                return 0;
            }            
        }
    }
};
