// https://leetcode.com/problems/candy/
// first scan from left to right, then scan from right to left
// greedy strategy: in each iteration, only consider one side relationship 
class Solution {
public:
    int candy(vector<int>& ratings) {
        // from left to right check
        vector<int> res(ratings.size(), 1);
        
        for (int i = 0; i < ratings.size()-1; i++) {
            if (ratings[i+1] > ratings[i] && res[i+1] <= res[i])
                res[i+1] = res[i] + 1;
        }
        
        for (int i = ratings.size()-1; i >= 1; i--) {
            // if (ratings[i-1] > ratings[i] && res[i-1] <= res[i])
            //     res[i-1] = res[i] + 1;
            
            if (ratings[i-1] > ratings[i])
                res[i-1] = max(res[i-1], res[i] + 1);
        }
        
        return accumulate(res.begin(), res.end(), 0);
    }
};