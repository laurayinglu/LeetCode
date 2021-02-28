// https://leetcode.com/problems/single-number/submissions/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // my solution: TC O(N), SC O(N)
        // can also use math: 2(a+b+c)-(a+a+b+b+c) = c
//         if(nums.size() == 1)
//             return nums[0];
        
//         unordered_map<int, int> m;
//         for (int i = 0; i < nums.size(); i++) {
//             m[nums[i]]++;
//         }
        
//         for (auto it = m.begin(); it != m.end(); it++) {
//             if(it->second == 1)
//                 return it->first;
//         }
        
//         return -1;
        
        // solution2: TC O(N), SC O(1)
        // bit manipulation XOR is commutative: 1^2^3 = 2^3^1 = 3^2^1
        // xor table: 0 ^ 0 -> 0; 1 ^ 1-> 0; 0 ^ 1-> 1; 1 ^ 0 -> 1
        // 4,1,2,1,2 => 0^4^1^2^1^2 = 0^(1^1)^(2^2)^4 = 0^0^0^4 = 4
        
        int res = 0;
        
        for (int i = 0; i < nums.size(); i++)
            res ^= nums[i];
        
        return res;
        
        
    }
};