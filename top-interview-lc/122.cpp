// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum = 0;
        for (int i = 1; i < prices.size(); i++){
            sum += max(prices[i]-prices[i-1], 0);
        }

        return sum;   
    }
};