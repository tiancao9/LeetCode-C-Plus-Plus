/*
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2
Note:
The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].

*/

// hash map, record sum from nums[0] to nums[i]
// if (sum-k) in map, res += m[sum-k]
// m[0] = 1
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        unordered_map<int, int> m;
        int sum = 0;
        m[0] = 1;
        for(int num: nums)
        {
            sum += num;
            if(m.count(sum-k))
                res += m[sum-k];
            m[sum]++;
        }
        
        return res;
    }
};
