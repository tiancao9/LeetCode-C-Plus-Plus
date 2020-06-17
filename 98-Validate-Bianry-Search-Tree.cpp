98. Validate Binary Search Tree
Medium

3014

435

Add to List

Share
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:

    2
   / \
  1   3

Input: [2,1,3]
Output: true
Example 2:

    5
   / \
  1   4
     / \
    3   6

Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.

// Devide and conqur, check if left or right is also BST and change the min/max range accordingly.
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
    bool isValidBST(TreeNode* root) {
      return validate_bst(root, LLONG_MIN, LLONG_MAX);
    }
private:
    bool validate_bst(TreeNode* root, long left, long right) {
        if (!root) return true;
        if (root->val > left && root->val < right) {
            return validate_bst(root->left, left, root->val) && validate_bst(root->right, root->val, right);
        } else {
            return false;
        }
    }
};
