Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

Note:

Given target value is a floating point.
You are guaranteed to have only one unique value in the BST that is closest to the target.
Example:

Input: root = [4,2,5,1,3], target = 3.714286

    4
   / \
  2   5
 / \
1   3

Output: 4

// Sol1: recursive.
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
    int closestValue(TreeNode* root, double target) {
        int cur_val = root->val;
        int next_val;
        TreeNode* next;
        if (target <= root->val) {
            next = root->left;
        } else {
            next = root->right;
        }
        if (!next) return root->val;
        next_val = closestValue(next, target);
        return abs(cur_val - target) > abs(next_val - target)? next_val:cur_val;
        
    }
};

// sol2: iteration.
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
    int closestValue(TreeNode* root, double target) {
        int closest_val = root->val;
        TreeNode* cur = root;
        while (cur) {
            if (abs(cur->val -target) < abs(closest_val - target)) {
                closest_val = cur->val;
            }
            if (cur->val <= target) {
                cur = cur->right;
            }
            else {
                cur = cur->left;
            }
        }
        return closest_val;        
    }
};
