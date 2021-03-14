// https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/


class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        // my solution 
        // int freq[101] = {0};
        // for (int i = 0; i < nums.size(); i++) {
        //     freq[nums[i]]++;
        // }
        
        // vector<int> res(nums.size());
        
        // for (int i = 0; i < nums.size(); i++) {
        //     res[i] = accumulate(freq, freq+nums[i], 0);
        // }
        
        // return res;

        // solution 2: 

        vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
            int freq[101] = {0};
            for (int i = 0; i < nums.size(); i++) {
                freq[nums[i]]++;
            }
            
            // this for loop is to record accumulate sum of freq[i] = sum{freq(0,i)}
            for (int i = 1; i <= 100; i++) {
                freq[i]+=freq[i-1];
            }
            
            vector<int> res(nums.size());
            
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == 0)
                    res[i] = 0;
                else
                    res[i] = freq[nums[i]-1];
            }
            
            return res;
    }
};