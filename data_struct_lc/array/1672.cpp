// https://leetcode.com/problems/richest-customer-wealth/

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        // sum row and find max
        int max = 0;
        for (int i = 0; i < accounts.size(); i++) {
            int sum = 0;
            for (int j = 0; j < accounts[0].size(); j++) {
                sum += accounts[i][j];
            }
            
            if (max < sum)
                max = sum;
        }
        
        return max;
    }
};