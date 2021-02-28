// https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    // DP idea: always add element if it's make the maxCur larger
    // if previous sum is negative then add 0 to current sum
    int maxSubArray(vector<int>& nums) {
        int maxCur = 0;
        int maxSoFar = INT_MIN;
        
        for (int i = 0; i < nums.size(); i++) {
            maxCur = max(nums[i], maxCur+=nums[i]); 
            maxSoFar = max(maxSoFar, maxCur);
        }
        
        return maxSoFar;
        
    }
};