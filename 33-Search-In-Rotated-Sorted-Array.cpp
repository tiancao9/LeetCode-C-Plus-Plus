33. Search in Rotated Sorted Array
Medium

3611

393

Add to List

Share
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

// Old sol.
class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        if (nums.empty()) return -1;
        int index = left_or_right(nums,0,nums.size() - 1,target);
        return index;
        
    }

private:
    int left_or_right(vector<int>& nums, int i, int j, int target)
    {
        
        int mid = (j-i)/2 + i;
        if(nums[mid] == target) return mid;
        if(i >= j && nums[i] != target) return -1;
        //if(i == j && nums[i] != target) return -1;
        //if(j - i == 1 && nums[i] != target && nums[j] != target)
            //return -1;
        //if(nums[i] == target) return i;
        //if(nums[j] == target) return j;
        
        
        if (nums[i] <= nums[mid]) 
        {
            if(target < nums[mid] && target >= nums[i])
                return left_or_right(nums,i,mid-1,target);
            else
                return left_or_right(nums,mid+1,j,target);
        }
        else
        {
            if(nums[i] <= target || nums[mid] > target)
            {
                return left_or_right(nums,i,mid-1,target);
            }
            else
            {
                return left_or_right(nums,mid+1,j,target);
            }
        }
        
    }
};
// New sol.
class Solution {
public:
    int search(vector<int>& nums, int target) {
      if (nums.empty()) return -1;
      int left = 0, right = nums.size()-1;
      int mid;
      while (left + 1 < right) {
        mid = left + (right - left) / 2;
        if (target == nums[mid]) return mid;
        // check whether mid before or after the rotation point.
        if (nums[mid] >= nums[left]) {
          // mid is before the rotation point.
          // check if target on the left or right to mid.
          if (target >= nums[left] && target < nums[mid]) {
            right = mid;
          } else {
              left = mid;
          }
        } else {
          // mid is after the rotation point.
          // check if target is before or after mid.
          if (target > nums[mid] && target <= nums[right]) {
              left = mid;
          } else {
              right = mid;
          }
        }
      }
      if (nums[left] == target) return left;
      if (nums[right] == target) return right;
      return -1;
    }
};
