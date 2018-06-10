/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(!nums[i])
            {
                left = i;
                while(i < nums.size() && !nums[i])
                    i++;
                if(i < nums.size()) 
                    swap(nums[left], nums[i]);
                i = left;
            }
        }
    }
};
