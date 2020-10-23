You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:

Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.
 

Constraints:

The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.

// Sol1. Dfs.
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int res = 0;
        dfs(nums, 0, 0, res, S);
        return res;
    }
private:
    void dfs(vector<int>& nums, int i, int cur, int& res, int S) {
        if (i == nums.size()) {
            if (cur == S) res++;
            return;
        }
        dfs(nums, i + 1, cur + nums[i], res, S);
        dfs(nums, i + 1, cur - nums[i], res, S);
    }
};

// Sol2. DP.
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        unordered_map<int, int> dp;
        dp[0] = 1;
        for (const int& num : nums) {
            unordered_map<int, int> tmp;
            for (auto& item : dp) {
                tmp[item.first + num] += item.second;
                tmp[item.first - num] += item.second;
            }
            dp = tmp;
        }
        return dp[S];
    }
};
