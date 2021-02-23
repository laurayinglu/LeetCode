// https://leetcode.com/problems/diameter-of-binary-tree/

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
    
    // wrong: the longest paths not always pass through the root
    // int maxDepth(TreeNode* r) {
    //     return (r)? (1+max(maxDepth(r->left), maxDepth(r->right))) : 0;
    // }
    // int diameterOfBinaryTree(TreeNode* root) {
    //     if (!root)
    //         return 0;
    //     return maxDepth(root->left)+maxDepth(root->right);
    // }
    
    int maxDepth(TreeNode* r, int& diameter) {
        if (!r)
            return 0;
        int left = maxDepth(r->left, diameter);
        int right = maxDepth(r->right, diameter);
        diameter = max(left + right, diameter);
        
        return 1+max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        maxDepth(root, diameter);
        return diameter;
    }
    
};