// https://leetcode.com/problems/contains-duplicate/
// use unordered_map to count freq
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;
            if (count[nums[i]] > 1)
                return true;
        }
        
        return false;
    }
};

// solution2: use set to store unique elements and check size
//  return nums.size() > unordered_set<int>(nums.begin(), nums.end()).size(); 