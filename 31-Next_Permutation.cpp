/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/
// from n to 0, find the 1st decreasing number nums[i-1], from i to n, find the least number nums [j] that still > nums[i-1]
// swap nums[i-1] and nums[j]
// sort nums[i:]
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size();
        int i;
        for(i = n-2; i>=0; i--)
        {
            if (nums[i] < nums[i+1])
            {
                for(int j = i+1; j<n; j++)
                {
                    if (nums[j] <= nums[i])
                    {
                        int temp = nums[j-1];
                        nums[j-1] = nums[i];
                        nums[i] = temp;
                        break;
                    }
                    if(j == n-1)
                    {
                        int temp = nums[j];
                        nums[j] = nums[i];
                        nums[i] = temp;
                        break;
                    }
                }
                break;
            }
        }
        
        sort(nums.begin()+i+1, nums.end());
        
        
    }
};

