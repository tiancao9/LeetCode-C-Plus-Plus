In a given array nums of positive integers, find three non-overlapping subarrays with maximum sum.

Each subarray will be of size k, and we want to maximize the sum of all 3*k entries.

Return the result as a list of indices representing the starting position of each interval (0-indexed). If there are multiple answers, return the lexicographically smallest one.

Example:

Input: [1,2,1,2,6,7,5,1], 2
Output: [0, 3, 5]
Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].
We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically larger.
 

Note:

nums.length will be between 1 and 20000.
nums[i] will be between 1 and 65535.
k will be between 1 and floor(nums.length / 3).

//Sol: dp. win(nums.size() - k + 1, 0) tracks the sums for the sub arrs. left(win.size(), 0) track the max val sub arr index from win[0] ... win[i]. right(win.size(), win.size() - 1) tracks the max val sub arr index from win[i] ... win[win.size() - 1]. Iterate win[i] and get the max_val = max (win[i] + win[left[i - k] + win[right[i + k]), returns the {let[i - k], i, right[i + k]}.
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> res(3, -1);
        if (nums.empty()) return res; 
        vector<int> win(nums.size() - k + 1, 0);
        vector<int> left(win.size(), 0);
        vector<int> right(win.size(), win.size() - 1);
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (i >= k) {
                sum -= nums[i - k];
            }
            if (i >= k-1) {
                win[i - k + 1] = sum;
            }
        }
        for (int i = 1; i < nums.size() - k + 1; i++) {
            if (win[i] > win[left[i-1]]) {
                left[i] = i;
            } else {
                left[i] = left[i-1];
            }
        }
        for (int i = nums.size() - k - 1; i >= 0; i--) {
            if (win[i] >= win[right[i+1]]) {
                right[i] = i;
            } else {
                right[i] = right[i+1];
            }
        }
        int max_val = INT_MIN;
        for (int i = k; i < win.size() - k; i++) {
            if (win[i] + win[left[i - k]] + win[right[i + k]] > max_val) {
                max_val = win[i] + win[left[i - k]] + win[right[i + k]];
                res = {left[i - k], i, right[i + k]};
            }
        }
        return res;
    }
};
