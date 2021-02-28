// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        // O(n^2)
//         if (prices.size() == 1)
//             return 0;
        
//         int res = 0;
//         for (int i = 0; i < prices.size(); i++) {
//             for (int j = i+1; j < prices.size(); j++){
//                 if (prices[j]-prices[i] > res)
//                     res = prices[j]-prices[i];
//             }
//         }
        
//         if (res <= 0)
//             return 0;
        
//         return res;
        
        // solution1
//         int min_price = INT_MAX;
//         int max_profit = 0;
//         for (int i = 0; i < prices.size(); i++) {
//             if (prices[i] < min_price)
//                 min_price = prices[i];
            
//             else if ((prices[i] - min_price)> max_profit)
//                 max_profit = prices[i] - min_price;
//         }
        
//         return max_profit;
        // solution2
        // [7,1,5,3,6,4]
        // if we are given difference array [0,-6,4,-2,3,-2]
        // then we need to find max subarray sum
        int maxCur = 0, maxSoFar = 0;
        for(int i = 1; i < prices.size(); i++) {
            maxCur = max(0, maxCur += prices[i] - prices[i-1]);
            maxSoFar = max(maxCur, maxSoFar);
        }
        return maxSoFar;
    }
};