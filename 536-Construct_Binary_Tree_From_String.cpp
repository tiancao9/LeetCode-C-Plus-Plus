You need to construct a binary tree from a string consisting of parenthesis and integers.

The whole input represents a binary tree. It contains an integer followed by zero, one or two pairs of parenthesis. The integer represents the root's value and a pair of parenthesis contains a child binary tree with the same structure.

You always start to construct the left child node of the parent first if it exists.

 

Example 1:


Input: s = "4(2(3)(1))(6(5))"
Output: [4,2,6,3,1,5]
Example 2:

Input: s = "4(2(3)(1))(6(5)(7))"
Output: [4,2,6,3,1,5,7]
Example 3:

Input: s = "-4(2(3)(1))(6(5)(7))"
Output: [-4,2,6,3,1,5,7]
 

Constraints:

0 <= s.length <= 3 * 104
s consists of digits, '(', ')', and '-' only.

// Recursion: parse the root value and then recurse for the left and right subtree.
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
    TreeNode* str2tree(string s) {
        if (s == "") return NULL;
        int k = 0;
        while(k < s.size() && s[k] != '(') {
           k++;
        }
        int root_val = ParseInteger(s.substr(0, k));        
        TreeNode* root = new TreeNode(root_val);
       
        if (s.size() > k + 1) {
            stack<char> st;
            int i = k;
            st.push(s[i++]);
            while (!st.empty() && i < s.size()) {
                if (s[i] == ')') st.pop();
                if (s[i] == '(') st.push('(');
                i++;
            }
            root->left =  str2tree(s.substr(k + 1, i - k - 2));
            if (i >= s.size()) return root;
            int j = i;
            st.push(s[j++]);
            while (!st.empty() && j < s.size()) {
                if (s[j] == ')') st.pop();
                if (s[j] == '(') st.push('(');
                j++;
            }
            root->right =  str2tree(s.substr(i + 1, j - i - 2));
        }
        
        return root;
    }
private:
    int ParseInteger(string s) {
        int res = 0;
        bool neg = false;
        int j = 0;
        if (s[0] == '-') {
            neg = true;
            j++;
        }
        while (j < s.size()) {
            res = res * 10 + (s[j++] - '0');
        }
        return neg? -1 * res : res;
    }
};
