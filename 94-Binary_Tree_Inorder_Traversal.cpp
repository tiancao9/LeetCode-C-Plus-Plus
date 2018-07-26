/*
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
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
    vector<int> inorderTraversal(TreeNode* root) {
        
     stack<TreeNode*> s;
     vector<int> result;
     
        
     if(root == NULL)
         return result;
     else
         s.push(root);
        
     while(root->left)
     {
         s.push(root->left);
         root = root->left;
     }
        
     while(!s.empty())
     {
         TreeNode* cur;
         cur = s.top();
         s.pop();
         result.push_back(cur->val);
         
         if(cur->right)
         {
             s.push(cur->right);
             cur = cur->right;
             while(cur->left)
             {
                 s.push(cur->left);
                 cur = cur->left;
             }             
         }         
     }
        
        return result;
        
    }        
};

//Sol2: while (!s.empty() || cur)

class Solution {
    

public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while(!s.empty() || cur)
        {
            if(cur)
            {
                s.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = s.top(); s.pop();
                res.push_back(cur->val);
                cur = cur->right;
            }
        }
     return res;
    }        
};
