/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*/
//Per each point, conside horizontally, min(left_max, right_max)-height[i]
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        if(height.empty()) return res;
        vector<int> left_max(height.size(),height[0]); //left_maxt[i] = max(height[0], height[1]...height[i-1])
        vector<int> right_max(height.size(), height[height.size()-1]);
        for(int i = 1; i < height.size(); i++)
            left_max[i] = max(left_max[i-1], height[i-1]);
        for(int i = height.size()-2; i >= 0; i--)
        {
            right_max[i] = max(right_max[i+1], height[i+1]);
            if(min(left_max[i], right_max[i]) > height[i])
                res += min(left_max[i], right_max[i])-height[i];
        }
        
        return res;
    }
};
