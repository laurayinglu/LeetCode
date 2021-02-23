// https://leetcode.com/problems/symmetric-tree/

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
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        
        return isSymmetric(root->left, root->right);
        
    }
    
    bool isSymmetric(TreeNode* l, TreeNode* r) {
        
        if (!l && !r)
            return true;
        else if(!l || !r) 
            return false;
        
        if (l->val != r->val)
            return false;
        
        return isSymmetric(l->left, r->right) && isSymmetric(l->right, r->left);
        
    }
    
    // solution2: iterative, using queue, different push order for left/right subtree
//     TreeNode *left, *right;
//     if (!root)
//         return true;

//     queue<TreeNode*> q1, q2;
//     q1.push(root->left);
//     q2.push(root->right);
//     while (!q1.empty() && !q2.empty()){
//         left = q1.front();
//         q1.pop();
//         right = q2.front();
//         q2.pop();
//         if (NULL == left && NULL == right)
//             continue;
//         if (NULL == left || NULL == right)
//             return false;
//         if (left->val != right->val)
//             return false;
//         q1.push(left->left);
//         q1.push(left->right);
//         q2.push(right->right);
//         q2.push(right->left);
//     }
//     return true;
};