// https://leetcode.com/problems/binary-tree-tilt/

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

// Post-Order DFS Traversal

class Solution {
public:
    int valueSum(TreeNode* r, int &totalTilt) {
        if(!r)
            return 0;
     
        int leftSum = valueSum(r->left,totalTilt);
        int rightSum = valueSum(r->right,totalTilt);
        
        totalTilt += abs(leftSum-rightSum);
        return r->val + leftSum + rightSum;

    }
    
    int findTilt(TreeNode* root) {
        int sum = 0;
        valueSum(root, sum);
        return sum;
    }
};