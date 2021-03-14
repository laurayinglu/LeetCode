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