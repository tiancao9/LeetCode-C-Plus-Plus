/*
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42
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
    
    int maxPathSum(TreeNode* root) {
        
        if(!root) return 0;
        int sum = INT_MIN;
        maxPath(root, sum);
        return sum;
    }
private:
    int maxPath(TreeNode* root, int & sum)
    {
        if(!root) return 0;
        int left = max(0, maxPath(root->left, sum)); // need max because the path does not need to be the whole path!!!
        int right = max(0, maxPath(root->right, sum)); // withot max(0, right), test case [2,-1] will fail, since we need only root 2
        sum = max(sum, left+root->val+right);
        return max(left, right) + root->val;
    }
};
