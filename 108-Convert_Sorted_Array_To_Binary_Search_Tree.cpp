/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        
        if(nums.size() == 0)
            return NULL;
        
        TreeNode* root;
        Insert_next(root, nums, 0, nums.size()-1);        
        return root;
    }
    
private:
    void Insert_next(TreeNode* &root, vector<int> nums, int i, int j)
    {
        if(i > j)
            return;
        int mid = i + (j-i)/2;
        root = new TreeNode(nums[mid]);
        Insert_next(root->left, nums, i, mid-1);
        Insert_next(root->right, nums, mid+1, j);
        
    }
};
