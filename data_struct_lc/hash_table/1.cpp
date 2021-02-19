// https://leetcode.com/problems/two-sum/submissions/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
//         for (int i = 0 ; i < nums.size(); i++) {
//             for (int j = i+1; j < nums.size(); j++){
//                 if (nums[i] + nums[j] == target){
//                     res.push_back(i);
//                     res.push_back(j);
//                 }
//             }
                
//         }
        
        // save into map<value, index> and find (target-a[i]) exists or not
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            // check if can find target - nums[i]
            int num = nums[i];
            auto it = m.find(target - num);
            if (it == m.end())
                m[num] = i;
            else {
                res.push_back(i);
                res.push_back(it->second);
                break;
            }
        }
        
        
        return res;
    }
};