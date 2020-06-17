Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Example 1:

Input: [1,3,null,null,2]

   1
  /
 3
  \
   2

Output: [3,1,null,null,2]

   3
  /
 1
  \
   2
Example 2:

Input: [3,1,4,null,null,2]

  3
 / \
1   4
   /
  2

Output: [2,1,4,null,null,3]

  2
 / \
1   4
   /
  3
Follow up:

A solution using O(n) space is pretty straight forward.
Could you devise a constant space solution?


Sol 1. O(n) space and O(nlog(n)) time, recursive.
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
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> nodes;
        vector<int> vals;
        inorder(root, nodes, vals);
        sort(vals.begin(), vals.end());
        for (int i = 0; i < nodes.size(); i++) {
            nodes[i]->val = vals[i]; 
        }
    }

private:
    void inorder(TreeNode* root,
                 vector<TreeNode*>& nodes,
                 vector<int>& vals) {
        if (!root) return;
        inorder(root->left, nodes, vals);
        vals.push_back(root->val);
        nodes.push_back(root);
        inorder(root->right, nodes, vals);
    }
};

Sol 2: Morris Traversal, threaded tree. O(n) time and O(1) space;
// Thread the tree first, then compare pre and cur's val, if pre->val > cur->val, mark the first pre as first and last cur as second, swap the value.
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
    void recoverTree(TreeNode* root) {
      TreeNode *pre = nullptr, *first = nullptr, *second = nullptr, *cur = root;
      if (!cur) return;
      while (cur) {
          // make a threaded tree.
          if (cur->left) {
              // Find the right most node of the left sub tree.
              TreeNode* p = cur->left;
              while (p->right && p->right != cur) p = p->right;
              if (!p->right) {
                  p->right = cur;
                  cur = cur->left;
                  continue;
              } else if (p->right == cur) {
                  p->right = NULL;
              }              
          }
          if (pre && pre->val > cur->val) {
              if (!first) first = pre;
              second = cur;
          }
          pre = cur;
          cur = cur->right;
      }
      swap(first->val, second->val);
    }
};

