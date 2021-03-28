// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        
        vector<int> res(2);
        while (l < r) {
            int sum = nums[l] + nums[r];
            if (sum == target){
                res[0] = l+1;
                res[1] = r+1;
                return res;
            }
            else if (sum < target){
                l++;
            }
            else
                r--;
        }
        
        return res;
    }
};

// 1 2 3 4 5 6 7 8 9 10  