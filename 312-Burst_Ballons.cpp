/*
Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

Note: 
(1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
(2) 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100

Example:

Given [3, 1, 5, 8]

Return 167

    nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
   coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
*/
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        //O(n^3), DP
        int N = nums.size();
        vector<vector<int>> dp(N+2, vector<int>(N+2, 0));
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        for(int l = 1; l <= N; l++)
            for(int begin = 1; begin <= N-l+1; begin++)
            {
                
                int end = begin + l -1;
                for(int last = begin; last <= end; last++)
                {
                dp[begin][end] = max(dp[begin][end], dp[begin][last-1]+dp[last+1][end]+nums[begin-1]*nums[last]* nums[end+1]);
                }
                
            }
        return dp[1][N];
    }
};
