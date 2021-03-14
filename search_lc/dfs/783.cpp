// https://leetcode.com/problems/minimum-distance-between-bst-nodes/
// same as 530

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

// my solution: traverse all node and sort and find min diff
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        vector<int> v;
        
        traverse(root, v);
        sort(v.begin(), v.end());
        int s = v.size();
        int res = INT_MAX;
        for(int i = 1; i < s; i++) {
            res = min(v[i]-v[i-1], res);
        }
        
        return res;
    }
    
    void traverse(TreeNode* r, vector<int>& v) {
       if(r == NULL)
           return;
        
        v.push_back(r->val);
        traverse(r->left, v);
        traverse(r->right, v);
    }
// solution 2: dfs inorder recursion, pre is the value of previous root value
    int minDiffInBST(TreeNode *root) {
        int res = INT_MAX, pre = -1;
        helper(root, pre, res);
        return res;
    }

    void helper(TreeNode *root, int &pre, int &res) {
        if (root) {
            helper(root->left, pre, res);
            if (pre != -1) {
                res = min(res, root->val - pre);
            }
            pre = root->val;
            helper(root->right, pre, res);
        }
    }
    
    
};