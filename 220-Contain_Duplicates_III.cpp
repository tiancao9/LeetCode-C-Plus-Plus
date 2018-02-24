/*
Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.

*/
O(nlogn) balanced BST
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long> s;
        int left = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(i - left > k) s.erase(nums[left++]);
            auto a = s.lower_bound((long long)nums[i]-t);
            if(a != s.end() && abs(nums[i] - *a) <= t) return true;
            s.insert(nums[i]);
        }
        return false;
    }
};
