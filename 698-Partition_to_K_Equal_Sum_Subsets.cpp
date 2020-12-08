Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into k non-empty subsets whose sums are all equal.

 

Example 1:

Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
Output: True
Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
 

Note:

1 <= k <= len(nums) <= 16.
0 < nums[i] < 10000.

// Sol.
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (int num : nums) sum += num;
        if (sum % k != 0) return false;
        vector<bool> visited = vector<bool>(nums.size(), false);
        sort(nums.begin(), nums.end(), greater<int>());
        return helper(0, nums, k, sum / k, 0, visited); 
    }
private:
    bool helper(int cur_sum, vector<int>& nums, int k, int target_sum, int start, vector<bool>& visited) {
        if (k == 1) return true;
        if (cur_sum > target_sum) return false;
        if (cur_sum == target_sum) return helper(0, nums, k - 1, target_sum, 0, visited);
        for (int i = start; i < nums.size(); i++) {
            if (visited[i]) continue;
            visited[i] = true;
            if (helper(cur_sum + nums[i], nums, k, target_sum, i + 1, visited)) {
                return true;    
            }
            visited[i] = false;
        }
        return false;
    }
};
