/*
Given a binary tree, return the postorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [3,2,1]
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
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> data;
        stack<TreeNode*> s;
        
        TreeNode *cur = root;
        TreeNode *prev = root;
        if (cur == NULL) return data;
        s.push(cur);
        
        while(!s.empty())
        {
            cur=s.top();
            
             if(cur->left==NULL && cur->right == NULL)
             {
                data.emplace_back(cur->val);
                prev=cur;
                s.pop();
             }
             else if (cur->left==prev || cur->right == prev)
             {
                data.emplace_back(cur->val);
                prev=cur;
                s.pop();
             }
            
            else if(cur->right != NULL || cur->left !=NULL) 
            {
                if (cur->right != NULL)
                        s.push(cur->right);
                if(cur->left != NULL)
                        s.push(cur->left);
            }
           
                
        }
        return data;
        
        
    }
};
