/*
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.

Credits:
Special thanks to @porker2008 for adding this problem and creating all test cases.
*/
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.empty() || nums.size() < 2) return 0;
        int Min = nums[0];
        int Max = nums[0];
        for(int num: nums)
        {
            if(num < Min) Min = num;
            if(num > Max) Max = num;
        }
        if(Max == Min) return 0;
        int len = (Max - Min) / nums.size() + 1;
        int n = nums.size();
        
        vector<vector<int>> bucket(n);
        for(int i = 0; i < nums.size(); i++)
        {
            int idx = (nums[i]-Min) / len;
            if(bucket[idx].empty())
            {
                bucket[idx].push_back(nums[i]);
                bucket[idx].push_back(nums[i]);
            }
            if(nums[i] < bucket[idx][0]) bucket[idx][0] = nums[i];
            if(nums[i] > bucket[idx][1]) bucket[idx][1] = nums[i];
        }
        int gap = 0;
        int prev = 0;
        for(int i = 0; i < n; i++)
        {
            if(bucket[i].empty()) continue;
            else
            {
                gap = max(gap, bucket[i][0] - bucket[prev][1]);
            }
            prev = i;
        }
        return gap;
    }
};
