Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.

Return the shortest such subarray and output its length.

 

Example 1:

Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Example 2:

Input: nums = [1,2,3,4]
Output: 0
Example 3:

Input: nums = [1]
Output: 0
 

Constraints:

1 <= nums.length <= 104
-105 <= nums[i] <= 105

// Sol1: O(n) space, O(nlogn) time.
// Sort the array, and find the start and end for the sub-array.
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        vector<int> cp = nums;
        sort(cp.begin(), cp.end());
        while(start <= nums.size() - 1 && nums[start] == cp[start]) start++;
        while(end >= start && nums[end] == cp[end]) end--;
        return end - start + 1;
    }
};

// Sol2: O(1) space, O(n) time.
// Tracks max from beggining to end, and update index end, and tracks min from the end to the begining and update index start.
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if (nums.empty()) return 0;
        int start = -1, end = -2;
        int mn = nums.back(), mx = nums[0];
        int n = nums.size();
        for (int i = 1; i < nums.size(); i++) {
            mn = min(mn, nums[n - i - 1]);
            mx = max(mx, nums[i]);
            if (mn < nums[n - i - 1]) start = n - i - 1;
            if (mx > nums[i]) end = i;
        }
        return end - start + 1;
    }
};
