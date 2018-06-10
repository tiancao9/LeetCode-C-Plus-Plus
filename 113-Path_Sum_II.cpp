/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        
        vector<vector<int>> res;
        vector<int> cur;
        int cur_sum = 0;
        
        if(!root)
            return res;
        
        find_path(res,cur,root,cur_sum,sum);        
        return res;
    }

private:
    void find_path(vector<vector<int>>& res, vector<int> cur, TreeNode* root, int cur_sum, int sum)
    {
        cur.push_back(root->val);
        
        if(!root->left && !root->right && root->val + cur_sum == sum)
            res.push_back(cur);                
            
        if(root->left)
            find_path(res,cur,root->left,cur_sum+root->val,sum);
             
        if(root->right)
            find_path(res,cur,root->right,cur_sum+root->val,sum);
        
 
    }
    
};
