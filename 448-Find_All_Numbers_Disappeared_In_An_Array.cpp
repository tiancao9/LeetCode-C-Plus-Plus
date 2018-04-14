/*
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
*/
// for nums[i], mark pos nums[i]'s number * -1
// return the array of positive number 
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        vector<int> data;
        
        for(int num: nums)
        {
            if (nums[abs(num)-1] > 0)
                nums[abs(num)-1] = nums[abs(num)-1] * -1;
        }
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
                data.emplace_back(i+1);
    
        }
        
        return data;
        
    }
};
