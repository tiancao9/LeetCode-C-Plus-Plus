Given a complete binary tree, count the number of nodes.

Note:

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Example:

Input: 
    1
   / \
  2   3
 / \  /
4  5 6

Output: 6

// Sol1, queue. T: O(N) + S: O(N).
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        queue<TreeNode*> q;
        if (!root) return 0;
        q.push(root);
        int res = 0;
        while (!q.empty()) {
            TreeNode* cur = q.front(); q.pop();
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
            res++;
        }
        return res;
    }
};

// Sol2. 'binary search'. 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        int h = GetHeight(root);
        while (root) {
            int right = GetHeight(root->right);
            if (right == h - 1) {
                res += 1 << h;
                root = root->right;
            } else {
                res += 1 << (h - 1);
                root = root->left;
            }
            h--;
        }
        return res;
    }
private:
    int GetHeight(TreeNode* cur) {
        return cur ? (1 + GetHeight(cur->left)) : -1;
    }
};
