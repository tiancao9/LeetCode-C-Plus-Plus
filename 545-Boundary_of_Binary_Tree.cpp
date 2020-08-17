Given a binary tree, return the values of its boundary in anti-clockwise direction starting from root. Boundary includes left boundary, leaves, and right boundary in order without duplicate nodes.  (The values of the nodes may still be duplicates.)

Left boundary is defined as the path from root to the left-most node. Right boundary is defined as the path from root to the right-most node. If the root doesn't have left subtree or right subtree, then the root itself is left boundary or right boundary. Note this definition only applies to the input binary tree, and not applies to any subtrees.

The left-most node is defined as a leaf node you could reach when you always firstly travel to the left subtree if exists. If not, travel to the right subtree. Repeat until you reach a leaf node.

The right-most node is also defined by the same way with left and right exchanged.

Example 1

Input:
  1
   \
    2
   / \
  3   4

Ouput:
[1, 3, 4, 2]

Explanation:
The root doesn't have left subtree, so the root itself is left boundary.
The leaves are node 3 and 4.
The right boundary are node 1,2,4. Note the anti-clockwise direction means you should output reversed right boundary.
So order them in anti-clockwise without duplicates and we have [1,3,4,2].
 

Example 2

Input:
    ____1_____
   /          \
  2            3
 / \          / 
4   5        6   
   / \      / \
  7   8    9  10  
       
Ouput:
[1,2,4,7,8,9,10,6,3]

Explanation:
The left boundary are node 1,2,4. (4 is the left-most node according to definition)
The leaves are node 4,7,8,9,10.
The right boundary are node 1,3,6,10. (10 is the right-most node).
So order them in anti-clockwise without duplicate nodes we have [1,2,4,7,8,9,10,6,3].

// Iteration.
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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        // Iterates 3 times for left_b, leaves, right_b;
        vector<int> res;
        if (!root) return res;
        stack<TreeNode*> s_r, s_rt;
        TreeNode *rt = root, *l = root->left, *r = root->right;
        if (root->left || root->right) res.push_back(root->val);
        while (l && (l->left || l->right)) {
            res.push_back(l->val);
            if (l->left) {
                l = l->left;
            }
            else {
                l = l->right;
            }
        }
        while (rt || !s_rt.empty()) {
            if (rt) {
                s_rt.push(rt);
                if (!rt->left && !rt->right) res.push_back(rt->val);
                rt = rt->left;
            } else {
                rt = s_rt.top(); s_rt.pop();
                rt = rt->right;
            }          
        }
        while (r && (r->left || r->right)) {
            s_r.push(r);
            if (r->right) {
                r = r->right;
            } else {
                r = r->left;
            }            
        }
        while (!s_r.empty()) {
            res.push_back(s_r.top()->val);
            s_r.pop();
        }
        return res;
    }
};

// Recursion.
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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        if (root->left || root->right) res.push_back(root->val);
        AddLeftBoundary(root->left, res);
        AddLeaves(root, res);
        AddRightBoundary(root->right, res);
        return res;
    }
private:
    // Adds the left boudary.
    void AddLeftBoundary(TreeNode* cur, vector<int>& res) {
        if (!cur || (!cur->left && !cur->right)) return;
        res.push_back(cur->val);
        if (cur->left) {
            AddLeftBoundary(cur->left, res);
        } else {
            AddLeftBoundary(cur->right, res);
        }
    }
    // Adds the leaves.
    void AddLeaves(TreeNode* cur, vector<int>& res) {
        if (!cur) return;
        if (!cur->left && !cur->right) {
            res.push_back(cur->val);
        }
        AddLeaves(cur->left, res);
        AddLeaves(cur->right, res);
    }
    // Adds the right boundary.
    void AddRightBoundary(TreeNode* cur, vector<int>& res) {
        if (!cur || (!cur->left && !cur->right)) return;
        if (cur->right) {
            AddRightBoundary(cur->right, res);
        } else {
            AddRightBoundary(cur->left, res);
        }
        res.push_back(cur->val);        
    }
};
