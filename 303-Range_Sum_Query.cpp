/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.
*/

//Create the pbj once, but query many times. Create a private sum vector that store sum[j]= nums[0]+... nums[j]
class NumArray {
public:
    NumArray(vector<int> nums) {
        int sum_cur = 0;
        for(int num: nums)
        {
            sum_cur += num;
            sum.push_back(sum_cur);
        }
    }
    
    int sumRange(int i, int j) {
        if(i == 0)
            return sum[j];
        else
            return sum[j] - sum[i-1];
    }
private:
    vector<int> sum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
