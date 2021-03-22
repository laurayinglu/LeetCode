// https://leetcode.com/problems/distribute-candies/

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        // find maximum number of unique element
        unordered_set<int> s;
        for (int c: candyType){
            s.insert(c);
        }
        
        int n = s.size();
        int t = candyType.size()/2;
        
        return min(n,t);
    }
};