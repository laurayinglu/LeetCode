// https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order/

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        //find the average first
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        
        int m = sum/2;
        int size = nums.size();
        
        // sort the vector 
        sort(nums.begin(), nums.end());
        int start = 0;
        int sub_sum = 0;
        
        vector<int> res;
        while (sub_sum <= m) {
            res.push_back(nums[size-1]);
            sub_sum += nums[size-1];
            size--;
        }
            
            
        return res;
    
    
        // vector<int> res;
        // auto sub_sum = 0, half_sum = accumulate(begin(nums), end(nums), 0) / 2;
        // priority_queue<int> pq(begin(nums), end(nums));
        // while (sub_sum <= half_sum) {
        //     res.push_back(pq.top());
        //     sub_sum += res.back();
        //     pq.pop();
        // }
        // return res;

    }
};