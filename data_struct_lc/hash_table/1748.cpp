// https://leetcode.com/problems/sum-of-unique-elements/

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        // my solution 
        // unordered_map<int, int> m;
        // for (int i = 0; i < nums.size(); i++) {
        //     m[nums[i]]++;
        // }
        
        // int sum = 0;
        
        // for (auto it = m.begin(); it != m.end(); it++) {
        //     sum += (it->second==1) ? it->first : 0;
        // }
        
        // return sum;

        // solution 2: one loop

        unordered_map<int, int> m;
        int res = 0;
        for (auto n : nums) {
            m[n]++;
            if (m[n] == 1)
                res += n;
            else if (m[n] == 2)
                res -= n;
            else
                res += 0;
        }
        
        return res;

    }
};