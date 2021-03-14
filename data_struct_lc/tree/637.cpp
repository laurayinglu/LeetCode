// https://leetcode.com/problems/average-of-levels-in-binary-tree/

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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if (!root)
            return res;
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        double sum = 0;
        int num = 0;
        TreeNode* curr;
        while(!q.empty()) {
            if (q.size() == 1){
                res.push_back(sum/num);
                break;
            }
            //cout << "hello" << endl;
            curr = q.front();
            q.pop();
            
            if (curr == NULL){
                res.push_back(sum/num);
                sum = 0;
                num = 0;
                if (!q.empty()) q.push(nullptr); // for last null 
            }
            else {
                if(curr->left) 
                    q.push(curr->left);
                if(curr->right) 
                    q.push(curr->right);
                sum += curr->val;
                num++;
            }
        }
        
        return res;
    }
};

// my another solution :
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        vector<double> res;
        if (!root)
            return res;
        
        q.push(root);
        while(!q.empty()) {
            TreeNode* curr = q.front();
            int size = q.size(); // number of nodes each level
            double sum = 0;
            for (int i = 0; i < size; i++) {
                sum += curr->val;
                if (curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
                q.pop();
                curr = q.front();
            }
            
            res.push_back(sum/size);
            
        }
        
        return res;
    }
};