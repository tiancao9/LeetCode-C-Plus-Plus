/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.

*/

class Solution:
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        if(len(nums1) > len(nums2)):
            return self.intersection(nums2, nums1)
        res = []
        dic = set()
        for num in nums1:
            dic.add(num)
        for num in nums2:
            if num in dic:
                res.append(num)
                dic.discard(num)
        return res
                
