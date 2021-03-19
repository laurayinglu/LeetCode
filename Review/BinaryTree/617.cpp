// https://leetcode.com/problems/merge-two-binary-trees/

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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2)
            return NULL;
        
        TreeNode* res;
        int nval = 0;
        if (!root1 && root2)
            nval = root2->val;
        else if (root1 && !root2)
            nval = root1->val;
        else
            nval = root1->val + root2->val;
        
        res = new TreeNode(nval);
        if(root1 && root2){
            res->left = mergeTrees(root1->left, root2->left);
            res->right = mergeTrees(root1->right, root2->right);
        }
        else if (root1 && !root2){
            res->left = mergeTrees(root1->left, NULL);
            res->right = mergeTrees(root1->right, NULL);
        }else{
            res->left = mergeTrees(NULL, root2->left);
            res->right = mergeTrees(NULL, root2->right);
        }
        
        return res;

        // solution better:
        if (!t1 && !t2) return nullptr;
        
        int val1 = t1 ? t1->val : 0;
        int val2 = t2 ? t2->val : 0;
        
        TreeNode* t = new TreeNode(val1 + val2);
        t->left = mergeTreesRec(t1 ? t1->left : nullptr, t2 ? t2->left : nullptr);
        t->right = mergeTreesRec(t1 ? t1->right : nullptr, t2 ? t2->right : nullptr);
        
        return t;
        
    }
};