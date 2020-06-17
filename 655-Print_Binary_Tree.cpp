Print a binary tree in an m*n 2D string array following these rules:

The row number m should be equal to the height of the given binary tree.
The column number n should always be an odd number.
The root node's value (in string format) should be put in the exactly middle of the first row it can be put. The column and the row where the root node belongs will separate the rest space into two parts (left-bottom part and right-bottom part). You should print the left subtree in the left-bottom part and print the right subtree in the right-bottom part. The left-bottom part and the right-bottom part should have the same size. Even if one subtree is none while the other is not, you don't need to print anything for the none subtree but still need to leave the space as large as that for the other subtree. However, if two subtrees are none, then you don't need to leave space for both of them.
Each unused space should contain an empty string "".
Print the subtrees following the same rules.
Example 1:
Input:
     1
    /
   2
Output:
[["", "1", ""],
 ["2", "", ""]]
Example 2:
Input:
     1
    / \
   2   3
    \
     4
Output:
[["", "", "", "1", "", "", ""],
 ["", "2", "", "", "", "3", ""],
 ["", "", "4", "", "", "", ""]]
Example 3:
Input:
      1
     / \
    2   5
   / 
  3 
 / 
4 
Output:

[["",  "",  "", "",  "", "", "", "1", "",  "",  "",  "",  "", "", ""]
 ["",  "",  "", "2", "", "", "", "",  "",  "",  "",  "5", "", "", ""]
 ["",  "3", "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]
 ["4", "",  "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]]
Note: The height of binary tree is in the range of [1, 10].

// Get Tree height for array height and width, recursively fill in tree value.
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
    vector<vector<string>> printTree(TreeNode* root) {
        // Get Tree Height.
        int h = GetHeight(root);
        int w = pow(2, h) - 1;
        // Initialize vector.
        vector<vector<string>> result(h, vector<string>(w, ""));
        // Fill in tree value.
        FillArray(result, 0, w-1, 0, h, root);
        return result;
    }
private:
    int GetHeight(TreeNode* node) {
        if (!node) return 0;
        return 1 + max(GetHeight(node->left), GetHeight(node->right));
    }
    
    void FillArray(vector<vector<string>>& res, int left, int right, int curh,
                   int h, TreeNode* node) {
        if (!node || curh == h) return;
        res[curh][(left+right)/2] = to_string(node->val);
        FillArray(res, left, (left+right)/2-1, curh+1, h, node->left);
        FillArray(res, (left+right)/2+1, right, curh+1, h, node->right);
    }
};
