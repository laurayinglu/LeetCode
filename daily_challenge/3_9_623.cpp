// https://leetcode.com/problems/add-one-row-to-tree/

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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        // edge case: d == 1
        // if (d == 1) return new TreeNode(v, root, NULL);
        // // support variables
        // int len;
        // queue<TreeNode*> q;
        // // populating q
        // q.push(root);
        // while (--d) {
        //     int len = q.size();
        //     for (int i = 0; i < len; i++) {
        //         // not deep enough yet case
        //         if (d > 1) {
        //             if (q.front()->left) q.push(q.front()->left);
        //             if (q.front()->right) q.push(q.front()->right);
        //         }
        //         // right depth reached!
        //         else {
        //             q.front()->left = new TreeNode(v, q.front()->left, NULL);
        //             q.front()->right = new TreeNode(v, NULL, q.front()->right);
        //         }
        //         q.pop();
        //     }
        // }
        // return root;
        queue<TreeNode*> q;
        q.push(root);
        int dep = 1;
        if (d == 1){
            TreeNode* n = new TreeNode(v);
            n->left = root;
            return n;
        }
        
        while(--d) {
            int len = q.size(); // level nodes
            for (int i = 0; i < len; i++) {
                TreeNode* curr = q.front();
                if(d > 1){
                    if(curr->left)
                        q.push(curr->left);
                    if(curr->right)
                        q.push(curr->right);
                }
                else {
                    curr->left = new TreeNode(v, curr->left, nullptr);
                    curr->right = new TreeNode(v, nullptr, curr->right);
                    //return root;
                }
                q.pop();
            }
        }
        
        return root;
        
    }
};
