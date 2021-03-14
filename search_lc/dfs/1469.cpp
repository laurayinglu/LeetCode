// Find All the Lonely Nodes
// In a binary tree, a lonely node is a node that is the only child of its parent node. 
// The root of the tree is not lonely because it does not have a parent node.

// Given the root of a binary tree, return an array containing the values 
// of all lonely nodes in the tree. Return the list in any order.

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public:
        vector<int> getLonelyNodes(TreeNode *root) {
            vector<int> res;
            if (!root)
                return res;
            queue<TreeNode*> q;
            q.push(root);

            while(!q.empty()) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left == NULL && curr->right != NULL)
                {
                    q.push(curr->right);
                    res.push_back(curr->right->val);
                }

                else if (curr->left != NULL && curr->right == NULL)
                {
                    q.push(curr->left);
                    res.push_back(curr->left->val);
                }

                if (curr->left != NULL && curr->right != NULL)
                {
                    q.push(curr->left);
                    q.push(curr->right);
                }
            }

            return res;

        }
};


// solution
class Solution {
 public:
  vector<int> getLonelyNodes(TreeNode* root) {
    vector<int> ans;

    dfs(root, false, ans);

    return ans;
  }

 private:
  void dfs(TreeNode* root, bool isLonely, vector<int>& ans) {
    if (!root)
      return;
    if (isLonely)
      ans.push_back(root->val);

    dfs(root->left, !root->right, ans);
    dfs(root->right, !root->left, ans);
  }
};