/*
Given a sorted integer array nums, where the range of elements are in the inclusive range [lower, upper], return its missing ranges.

Example:

Input: nums = [0, 1, 3, 50, 75], lower = 0 and upper = 99,
Output: ["2", "4->49", "51->74", "76->99"]
*/
class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        
        vector<string> data;
        
        if (nums.empty())
        {
            if ((upper - lower) == 0)
                data.emplace_back(to_string(lower));
            else
                data.emplace_back(to_string(lower) + "->" + to_string(upper));
                
            return data;
        }
        
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                if (nums[i] == lower)
                    continue;
                else if ((lower + 1) == nums[i])
                    data.emplace_back(to_string(lower));
                else if ((lower + 1) < nums[i])
                    data.emplace_back(to_string(lower) + "->" + to_string(nums[i] - 1));
            }
            
            if (i > 0)
            {
                if (nums[i] == nums[i - 1])
                    continue;
                else if ((nums[i] - nums[i - 1]) == 2)
                    data.emplace_back(to_string(nums[i] - 1));
                else if ((nums[i] - 2) > nums[i-1])
                    data.emplace_back(to_string(nums[i-1] + 1) + "->" + to_string(nums[i] - 1));
            }
        }
        
        
                if ((upper -1 ) == nums[n-1])
                    data.emplace_back(to_string(upper));
                if (nums[n-1] < (upper - 1))
                    data.emplace_back(to_string(nums[n-1]+1) + "->" + to_string(upper));
            
        
        return data;
    }
    
};
