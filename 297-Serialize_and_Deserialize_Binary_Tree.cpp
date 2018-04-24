/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

For example, you may serialize the following tree

    1
   / \
  2   3
     / \
    4   5
as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        if(!root) return res;
        queue<TreeNode*> q;
        res += to_string(root->val) + "#";
        q.push(root);
        while(!q.empty())
        {
            TreeNode* cur = q.front(); q.pop();
            if(cur->left)
            {
                res += to_string(cur->left->val) + "#";
                q.push(cur->left);
            }
            else
                res += "n#";
            if(cur->right)
            {
                res += to_string(cur->right->val) + "#";
                q.push(cur->right);
            }
            else
                res += "n#";
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {        
        queue<TreeNode*> q;
        if (data == "")
            return NULL;
        int pos = data.find("#");
        TreeNode* root = new TreeNode(stoi(data.substr(0,pos)));
        data.erase(0, pos+1);
        q.push(root);
        while(!q.empty())
        {
            TreeNode* cur = q.front(); q.pop();
            pos = data.find("#");
            if(data.substr(0,pos) == "n")
            {
                cur->left = NULL;
                data.erase(0,pos+1);
            }
            else
            {
                cur->left = new TreeNode(stoi(data.substr(0, pos)));
                data.erase(0,pos+1);
                q.push(cur->left);    
            }
            
            pos = data.find("#");
            if(data.substr(0,pos) == "n")
            {
                cur->right = NULL;
                data.erase(0,pos+1);
            }
            else
            {
                cur->right = new TreeNode(stoi(data.substr(0, pos)));
                data.erase(0,pos+1);
                q.push(cur->right);    
            }
            
        }
        return root;
    }    

};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

