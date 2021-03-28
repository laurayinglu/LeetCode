// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        //find largest amnong candies
        int maxi = candies[0];
        for (int c: candies){
            if (c > maxi)
                maxi = c;
        }
        
        // compare
        vector<bool> res(candies.size());
        for (int i = 0; i < candies.size(); i++){
            if (candies[i]+extraCandies >= maxi)
                res[i] = true;
            else
                res[i] = false;
        }
        
        return res;
    }
};