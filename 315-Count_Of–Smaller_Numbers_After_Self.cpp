/*
You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example:

Given nums = [5, 2, 6, 1]

To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
Return the array [2, 1, 1, 0].
*/

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        //binary search 
        vector<int> res;
        vector<int> count(nums.size(), 0);
        for(int i = nums.size()-1; i >= 0; i--)
        {
            if(res.empty()) {
                res.push_back(nums[i]);
                continue;
            }
            int left = 0;
            int right = res.size() - 1;
            while(left < right)
            {
                int mid = left + (right - left)/2;
                if(nums[i] <= res[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            
            if(nums[i] > res[left])
            {
                res.insert(res.begin()+left+1, nums[i]);
                count[i] = left + 1;
            }
            else
            {
                res.insert(res.begin() + left, nums[i]);
                count[i] = left;
            }
            
        }
        return count;
    }
};
