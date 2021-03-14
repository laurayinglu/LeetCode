// https://leetcode.com/problems/range-sum-of-bst/

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
    int rangeSumBST(TreeNode* root, int low, int high) {
        // this solution didn't utilize the fact of BST
        if (!root)
            return 0;
        
        int res = (root->val >= low && root->val <= high) ? root->val: 0;

        return res + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);

        // utilize BST
        if (!root)
            return 0;
        
        if (root->val >= low && root->val <= high)
            return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
        else if (root->val < low)
            return rangeSumBST(root->right, low, high);
        else
            return rangeSumBST(root->left, low, high);
    }
};