// https://leetcode.com/problems/longest-harmonious-subsequence/
// only need to check key-1/key+1 , don't have to check both
class Solution {
public:
    int findLHS(vector<int>& nums) {
        // solution1: use hashmap: TC O(n), SC O(n)
        unordered_map<int, int> m;
        for (int i = 0; i<nums.size(); ++i)
        {
            m[nums[i]]++;
        }
        
        int res = 0;
        
        for(auto it:m)
            if(m.count(it.first-1)) // key-1 is present
                res = max(res, it.second+m[it.first-1]);

        return res;

        // solution2: sort TC: O(nlogn) SC: O(1)
        // sort(nums.begin(), nums.end());
        // int maxlen = 0, left = 0;
        // for (int right = 0; right < nums.size(); right++){
        //     while (nums[right] - nums[left] > 1)
        //         left++;
            
        //     if (nums[right] - nums[left] == 1)
        //         maxlen = max(maxlen, right - left + 1);
        // }
        // return maxlen;
    }
};