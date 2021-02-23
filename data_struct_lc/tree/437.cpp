// https://leetcode.com/problems/path-sum-iii/

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
//     int helper(TreeNode* root, int sum) {
//         if (!root)
//             return 0;
//         int count = (root->val == sum) ? 1: 0;
//         count += helper(root->left, sum-root->val);
//         count += helper(root->right, sum-root->val);
//         return count;
//     }
    
//     int pathSum(TreeNode* root, int sum) {
//         if (!root)
//             return 0;
        
//         return helper(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
//     }
    
    int help(TreeNode* root, int sum, unordered_map<int, int>& store, int pre) {
        if (!root) return 0;
        root->val += pre;
        int res = (root->val == sum) + (store.count(root->val - sum) ? store[root->val - sum] : 0);
        store[root->val]++;
        res += help(root->left, sum, store, root->val) + help(root->right, sum, store, root->val);
        store[root->val]--;
        return res;
    }

    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> store;
        return help(root, sum, store, 0);
    }
};