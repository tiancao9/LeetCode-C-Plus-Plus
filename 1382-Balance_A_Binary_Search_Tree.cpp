Given a binary search tree, return a balanced binary search tree with the same node values.

A binary search tree is balanced if and only if the depth of the two subtrees of every node never differ by more than 1.

If there is more than one answer, return any of them.

// Gather the vals (sorted) via in-order traversal.
// Construct the balanced BTS recursively, with vals, left, right.
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
    TreeNode* balanceBST(TreeNode* root) {
        if (!root) return root;
        stack<TreeNode*> s;
        TreeNode* cur = root;
        vector<int> vals;
        while (!s.empty() || cur) {
            if (cur) {
                s.push(cur);
                cur = cur->left;
            } else {
                cur = s.top();
                vals.push_back(cur->val);
                s.pop();
                cur = cur->right;
            }
        }
        for (const int& cur : vals) std::cout << cur << " ";
        std::cout << std::endl;
        return ConstructBalancedBST(vals, 0, vals.size() - 1);
    }

private:
    TreeNode* ConstructBalancedBST(vector<int>& vals, int i, int j) {
        if (j < i) return NULL;
        TreeNode* cur = new TreeNode(vals[i + (j - i) / 2]);
        if (i == j) return cur;
        cur->left = ConstructBalancedBST(vals, i, i + (j - i) / 2 - 1);
        cur->right = ConstructBalancedBST(vals, i + (j - i) / 2 + 1, j);
        return cur;    
    }
};
