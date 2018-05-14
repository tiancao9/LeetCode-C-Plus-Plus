/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/
// Find Kth element, binary search
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int m = nums1.size();
        int n = nums2.size();
        if((m+n) % 2 == 0)
            return (1.0 * find_kth(nums1, 0, nums2, 0, (m+n)/2) + 1.0 * find_kth(nums1, 0, nums2, 0, (m+n)/2+1))/2;
        else
            return find_kth(nums1, 0, nums2, 0, (m+n)/2+1);
    }
    
private:
    double find_kth(vector<int> nums1, int begin1, 
                 vector<int> nums2, int begin2, int k)
    {
        if(begin1 >= nums1.size()) 
            return nums2[begin2 + k -1];
        if(begin2 >= nums2.size())
            return nums1[begin1 + k -1];
        if(k == 1)
            return min(nums1[begin1], nums2[begin2]);
        
        if(begin2 + k/2 -1 >= nums2.size())
            return find_kth(nums1, begin1+k/2, nums2, begin2, k-k/2);
        else if(begin1 + k/2 -1 >= nums1.size())
            return find_kth(nums1, begin1, nums2, begin2+k/2, k-k/2);
        
        if(begin2 + k/2 -1 >= nums2.size() || nums1[begin1+k/2-1] < nums2[begin2+k/2-1])
            return find_kth(nums1, begin1+k/2, nums2, begin2, k-k/2);
        else 
            return find_kth(nums1, begin1, nums2, begin2+k/2, k-k/2);
    }
};
