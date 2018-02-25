/*
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size() <= 1) return -1;
        int slow = nums[0];
        int fast = nums[nums[0]];
        // 2s = s + n*c  -> s = n*c
        // s = x + a
        // n*c = x + a
        // x = (n-1)*c + c - a -> the reason/prove for the 2nd while loop 
        while(slow != fast && slow < nums.size() && fast < nums.size())
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        if(fast >= nums.size()) return -1;
        fast = 0;
        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
        
    }
};
