Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
Note:

There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?

// DP, O(n^2).
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> dp(nums.size(), 1);
        int res = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    res = max(res, dp[i]);
                }
            }
        }
        return res;
    }
};

// O(nlogn).
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> bs;
        bs.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            int index = BinarySearch(bs, nums[i]);
            if (index == -1) {
                bs.push_back(nums[i]);
            } else {
                bs[index] = nums[i];
            }
        }
        return bs.size();
    }
private:
    int BinarySearch(vector<int>& bs, int target) {
        int left = 0;
        int right = bs.size() - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (bs[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        if (bs[left] >= target) return left;
        if (bs[right] >= target) return right;
        return -1;
    }
};
