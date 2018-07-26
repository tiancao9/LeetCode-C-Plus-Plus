/*
Given a binary tree, return the preorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,2,3]
Follow up: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> data;
        stack<TreeNode*> s;
        TreeNode *cur;
        cur=root;
        if (cur == NULL) return data;
        s.push(cur);
        while(!s.empty())
        {
            cur = s.top();
            data.emplace_back(cur->val);
            s.pop();
            if (cur->right!=NULL)
                s.push(cur->right);
            if (cur->left!=NULL)
                s.push(cur->left);
            
        }
        return data;
    }
};
