/*
Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....

For example, given nums = [3, 5, 2, 1, 6, 4], one possible answer is [1, 6, 2, 5, 3, 4].

*/
//Sort the vector and 2 pointer
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        
       
        int n = nums.size();
        int m = n-1;
        int j = 0;
       
        vector<int> data (n,0);
        
        sort(nums.begin(), nums.begin()+n);
        
        
        for (int i = 0; i < n; i++)
        {
            
            if (i%2 == 0)
                {
                    data[i] = nums[j];
                    j++;
                }
            else 
                {
                    data[i] = nums[m];
                    m--;
                }
            
        }
        
        for (int i = 0; i < n; i++)
        {
            nums[i] = data[i];
        }
        
    }
};
