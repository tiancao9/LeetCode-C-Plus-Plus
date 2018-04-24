/*
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int left = 1;
        int right = nums.size() - 2;
        
        if(nums.size() == 1)
            return 0;
            
        
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
                return mid;
            else if (nums[mid] > nums[mid-1] && nums[mid] < nums[mid+1])
                left = mid + 1;
            else 
                right = mid - 1;
            
        }
        
        if(nums[0] < nums[1])
            return nums.size()-1;
        else
            return 0;
        
        /*O(N) solution
        for (int i = 1; i < nums.size(); i++)
        {
            if(nums[i] < nums[i-1])
                return i-1;
        }
        return nums.size()-1;
        */
        
    }
};
