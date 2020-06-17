78. Subsets
Medium

2796

66

Add to List

Share
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

// Recursive.
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> res;
        vector<int> cur;
        res.push_back(cur);
        for(int i = 1; i <= nums.size(); i++)
            dfs(res, cur, i, 0, nums);
        
        return res;
    }

private:
    void dfs(vector<vector<int>>& res, vector<int>& cur, int n, int i, vector<int> nums)
    {
        if(cur.size() == n)
        {
            res.push_back(cur);
            return;
        }
        for(int j = i; j < nums.size(); j++)
        {
            cur.push_back(nums[j]);
            dfs(res, cur, n, j+1, nums);
            cur.pop_back();
        }
    }
};

// Use only 4 arg in dfs;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<vector<int>> res;
      vector<int> cur;

      if(nums.empty()) {
        res.push_back(cur);
        return res;
      }
      // DFS, search an add all the subsets.
      dfs(res, cur, 0, nums);
      return res;
    }
private:
    void dfs(vector<vector<int>>& res, vector<int>& cur, int index,
             vector<int> nums) {
      res.push_back(cur);
      if (index == nums.size()) return;
      for(int i = index; i < nums.size(); i++) {
        cur.push_back(nums[i]);
        // Next element can only search from nums[i+1]...nums[n];
        dfs(res, cur, i+1, nums);
        cur.pop_back();
      }
    }
q
};
