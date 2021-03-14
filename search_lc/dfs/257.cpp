// https://leetcode.com/problems/binary-tree-paths/

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

// solution 1: recursive
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        //string s = to_string(root->val);
       
        vector<string> res;
        if (!root)
            return res;
        helper(root, res, to_string(root->val));
        return res;
    }
    
    void helper(TreeNode* root, vector<string> &res, string s) {
        if (root) {
            
            if (!root->left && !root->right){
                res.push_back(s);
                return; 
            }  
            
            if (root->left)
                helper(root->left, res, s + "->" + to_string(root->left->val));
            
            if (root->right)
                helper(root->right, res, s + "->" + to_string(root->right->val));
            
        }
    }
};

// solution 2 DFS using stack


// solution 3 BFS using queue