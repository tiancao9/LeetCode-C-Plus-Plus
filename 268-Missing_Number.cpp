/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

Example 1

Input: [3,0,1]
Output: 2
Example 2

Input: [9,6,4,2,3,5,7,0,1]
Output: 8
*/

// for 0 to n, expected_sum = (0+max) * (max-0+1) /2
// if (expected_sum - sum == 0 && 0 exist in array), return max + 1, else return expected_sum - sum

class Solution:
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        sum_nums = 0
        min_nums = nums[0]
        max_nums = nums[0]
        for num in nums:
            sum_nums += num
            if num < min_nums:
                min_nums = num
            if num > max_nums:
                max_nums = num
        sum_expected = (max_nums) * (max_nums+1) / 2
        if(sum_expected - sum_nums == 0 and min_nums == 0):
            return max_nums + 1
        return int(sum_expected - sum_nums)
