/*
Given a sorted integer array without duplicates, return the summary of its ranges.

Example 1:
Input: [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Example 2:
Input: [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
*/
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        
        for(int i = 0; i < nums.size(); i++)
        {
            int left = i;
            while(i < nums.size()-1 && nums[i+1] == nums[i]+1)
                i++;
            string cur = to_string(nums[left]);
            if(i > left)
            {
                cur += "->";
                cur += to_string(nums[i]);    
            }
            res.push_back(cur);
        }
        return res;
    }
