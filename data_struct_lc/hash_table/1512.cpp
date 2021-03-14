// https://leetcode.com/problems/number-of-good-pairs/

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        // my solution : brute force
//         int res = 0;
//         for (int i = 0; i < nums.size(); i++) {
//             for (int j = i+1; j < nums.size(); j++) {
//                 if (nums[i] == nums[j])
//                     res++;
//             }
//         }
        
//         return res;
        
        // my solution 2: 
//         unordered_map<int,vector<int>> s;
//         int res = 0;
//         for (int i = 0; i < nums.size(); i++) {
//             s[nums[i]].push_back(i);
//         }
        
//         // (0,2,3) 2+1 = n*(n-1)/2 = 3*2/2 = 3
//         // 0,1,2,3 3+2+1 = 4*3/2 = 6
        
//         for(auto it = s.begin(); it != s.end(); it++) {
//             res += (it->second.size())*(it->second.size()-1)/2;
//         }
        
//         return res;
        
        // solution 3: count the number of occurrence
        int res = 0;
        unordered_map<int, int> count;
        for (int a: nums) {
            //cout << count[a] << endl;
            res += count[a]++;
            //cout << count[a] << endl;
        }
        return res;
    }
};