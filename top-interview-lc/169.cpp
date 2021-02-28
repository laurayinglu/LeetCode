// https://leetcode.com/problems/majority-element/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // solution1: TC O(N)  SC O(N)
//         unordered_map<int, int> m;
//         int res = 0;
//         for (int i = 0; i < nums.size(); i++)
//             m[nums[i]]++;
        
//         for (auto it = m.begin(); it != m.end(); it++){
//             if (it->second > floor(nums.size()/2))
//                 res = it->first;
//         }
        
//         return res;
        
        
        // solution2: TC O(N)  SC O(1)
        // Boyer-Moore Voting Algorithm
        int count = 0;
        int candidate = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0)
                candidate = nums[i];
            
            count += (nums[i] == candidate)?1:-1;
        }
        
        return candidate;
    }
};