Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.

// Scan twice, 1st time swap nums[i] to pos i-1
// Second time, return the 1st nums[i] != i+1
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > 0 && nums[i] != i+1 && nums[i]-1 < nums.size())
            {
                swap(nums[nums[i]-1], nums[i]);
                if(nums[i]!= nums[nums[i]-1]) i--;
            }
            else if(nums[i] == i+1)
                continue;
        }
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != i+1)
                return i+1;
        }
        
        return nums.size()+1;
    }
};
