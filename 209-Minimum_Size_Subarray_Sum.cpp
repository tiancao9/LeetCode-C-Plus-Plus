Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

Example: 

Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.
Follow up:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n). 

// 2 pointers.
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int left = 0, right = 0;
        int res = INT_MAX;
        if (nums.empty()) return 0;
        int sum = 0;
        while (right < nums.size()) {
            sum += nums[right];
            while (right < nums.size() && sum < s) {
                right++;
                if(right < nums.size()) {
                    sum += nums[right];
                }
            }
            if (right == nums.size()) break;
            while (left < right && sum >= s) {
                sum -= nums[left++];
            }
            int new_length = sum < s ? right - left + 2 : 1;
            res = min(res, new_length);
            right++;
        }
        return res == INT_MAX ? 0 : res;
    }
};
