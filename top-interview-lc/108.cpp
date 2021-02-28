// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

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
    TreeNode* helper(vector<int> &nums, int start, int end) {
        if (start > end)
            return NULL;
        
        int mid = (start+end)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helper(nums, start, mid-1); // get the mid of left half and make it left child of the root
        root->right = helper(nums, mid+1, end);
        
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0)
            return NULL;
        return helper(nums, 0, nums.size()-1);
    }
};


// rmk:
// 0,1,2,3,4,5,6
//   3
//  2 4
// 1   5
//0     6
// above is not height-balanced since the height of node 2 differ more than 1