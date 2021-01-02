Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2
 

Constraints:

1 <= nums.length <= 3 * 104
0 <= nums[i] <= 105

// Sol: BFS.
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.empty() || nums.size() == 1) return 0;
        Helper(nums, 0, 0, 0);
        return min_nums_;
    }
private:
    int min_nums_ = INT_MAX;
    void Helper(vector<int>& nums, int start, int stop, int cur_jumps) {
        int max_stop = start + 1;
        cur_jumps++;
        for (int i = start; i <= stop; i++) {
            if (i + nums[i] >= nums.size() - 1) {
                min_nums_ = cur_jumps;
                return;
            }
            max_stop = max(max_stop, i + nums[i]);
        }
        Helper(nums, stop + 1, max_stop, cur_jumps);
    }
};
