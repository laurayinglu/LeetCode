// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
// idea is to mark seen integers
// [4,3,2,7,8,2,3,1] -> [1,1,1,1,0,0,1,1]
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        vector<int> res;
        
        // correspond index with num in nums
        for (int i = 0; i < nums.size(); i++) {
            int cor_pos = abs(nums[i])-1;
            // mark the value in cor_p os
            if (nums[cor_pos] > 0)
                nums[cor_pos] = -nums[cor_pos];
        }
        
        // loop through the index 
        // push_back index that's not negative
        for (int i = 0 ; i < nums.size(); i++){
            if (nums[i] > 0)
                res.push_back(i+1);
        }
            
        return res;
    }
};

// 442: similar questions: https://leetcode.com/problems/find-all-duplicates-in-an-array/
// still negate seen values and store them if find negative
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        
        for (int i = 0; i < nums.size(); i++){
            int pos = abs(nums[i]) - 1;
            if (nums[pos] > 0) 
                nums[pos] = -nums[pos];
            else if (nums[pos] < 0) 
                res.push_back(pos+1);
        }
        
        return res;
    }
};
// if consider using space O(n)
// use a unordered_map and count freq of each int