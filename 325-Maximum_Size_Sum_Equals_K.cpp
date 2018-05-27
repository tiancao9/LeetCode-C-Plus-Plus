/*

Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.

Note:
The sum of the entire nums array is guaranteed to fit within the 32-bit signed integer range.

Example 1:

Input: nums = [1, -1, 5, -2, 3], k = 3
Output: 4 
Explanation: The subarray [1, -1, 5, -2] sums to 3 and is the longest.
Example 2:

Input: nums = [-2, -1, 2, 1], k = 1
Output: 2 
Explanation: The subarray [-1, 2] sums to 1 and is the longest.
Follow Up:
Can you do it in O(n) time?

*/

// parsial sum: s[i] means sum of nums[0], nums[1]...nums[i]
// use hash map to save sum and ending index, if k exist in hash map, max = sum[k] + 1
// for each partial sum, check if k + cur_sum exist in hash map, if yes, max(max_length, sum[k+cur_sum]-i)

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> sum; //map of {sum , ending index}
        int max_length = 0;
        int cur_sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            cur_sum += nums[i];
            sum[cur_sum] = i;
        }
        
        if(sum.count(k)) max_length = sum[k]+1;
        cur_sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            cur_sum += nums[i];
            if(sum.count(cur_sum + k))
                max_length = max(max_length, sum[cur_sum+k]-i);
        }
        
        return max_length;
        
    }
};
