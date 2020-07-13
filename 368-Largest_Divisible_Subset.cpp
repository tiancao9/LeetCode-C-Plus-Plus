Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:

Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

Input: [1,2,3]
Output: [1,2] (of course, [1,3] will also be ok)
Example 2:

Input: [1,2,4,8]
Output: [1,2,4,8]

// Sol: DP. vector<pair<int, int>> dp. dp[i].first counts the subset length, dp[i].second counts the last index of the subset.
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
      if (nums.empty()) return nums;
      vector<int> res;
      sort(nums.begin(), nums.end());
      vector<pair<int, int>> dp(nums.size());
      int cnt = 0;
      int last_index = 0;
      for (int i = 0; i < nums.size(); i++) {
        for (int j = i; j >= 0; j--) {
          if (nums[i] % nums[j] == 0 && dp[i].first < dp[j].first + 1) {
              dp[i].first = dp[j].first + 1;
              dp[i].second = j;
              if (cnt < dp[i].first) {
                  cnt = dp[i].first;
                  last_index = i;
              }
          }
        }
      }
      for (int i = 0; i < cnt; i++) {
        res.push_back(nums[last_index]);
        last_index = dp[last_index].second;
      }
      return res;
    }
};

