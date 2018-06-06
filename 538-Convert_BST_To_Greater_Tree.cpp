/*
Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.

Example:

Input: The root of a Binary Search Tree like this:
              5
            /   \
           2     13

Output: The root of a Greater Tree like this:
             18
            /   \
          20     13
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
    TreeNode* convertBST(TreeNode* root) {
        int cur = 0;
        convert_helper(root, cur);
        return root;
    }
    
private:
    void convert_helper(TreeNode* root, int &cur)
    {
        if(!root) return;
        convert_helper(root->right, cur);
        root->val += cur;
        cur = root->val;
        convert_helper(root->left, cur);
    }
};
