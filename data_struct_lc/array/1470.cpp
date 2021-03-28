// https://leetcode.com/problems/shuffle-the-array/

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res(nums.size());
        int idx = 0;
        for (int i = 0; i < n; i++) {
            res[idx] = nums[i];
            res[idx+1] = nums[n+i];
            idx = idx + 2;
        }
        
        return res;
    }
};