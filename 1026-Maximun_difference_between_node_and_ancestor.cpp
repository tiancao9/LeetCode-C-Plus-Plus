Given the root of a binary tree, find the maximum value V for which there exists different nodes A and B where V = |A.val - B.val| and A is an ancestor of B.

(A node A is an ancestor of B if either: any child of A is equal to B, or any child of A is an ancestor of B.)

 

Example 1:



Input: [8,3,10,1,6,null,14,null,null,4,7,13]
Output: 7
Explanation: 
We have various ancestor-node differences, some of which are given below :
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.
 

Note:

The number of nodes in the tree is between 2 and 5000.
Each node will have value between 0 and 100000.

// Sol1: recursive, tracking min_val and max_val for the route and keeping update max_diff.
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
//Sol1: recursive.
class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        return FindMaxDiff(root, INT_MAX, INT_MIN);
    }
private:
    int FindMaxDiff(TreeNode* root, int min_val, int max_val) {
        if (!root) return 0;
        if (root->val < min_val) min_val = root->val;
        if (root->val > max_val) max_val = root->val;
        max_diff = max(max_diff, max_val - min_val);
        FindMaxDiff(root->left, min_val, max_val);
        FindMaxDiff(root->right, min_val, max_val);
        return max_diff;
    }
    int max_diff = 0;
};
//Sol2: iterative. stack + pair<TreeNode*, pair<int(min), int(max)>>.
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
    int maxAncestorDiff(TreeNode* root) {
        if (!root) return 0;
        int max_diff = 0;
        stack<pair<TreeNode*, pair<int, int>>> s;
        s.push(make_pair(root, make_pair(root->val, root->val)));
        while (!s.empty()) {
            auto cur = s.top(); s.pop();
            max_diff = max(max_diff, cur.second.second - cur.second.first);
            if (cur.first->right) {
                s.push(make_pair(cur.first->right, make_pair(min(cur.second.first, cur.first->right->val), max(cur.second.second, cur.first->right->val))));
            }
            if (cur.first->left) {
                s.push(make_pair(cur.first->left, make_pair(min(cur.second.first, cur.first->left->val), max(cur.second.second, cur.first->left->val))));
            }
        }
        return max_diff;
    }
};
