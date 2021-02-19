
// https://leetcode.com/problems/degree-of-an-array/

/*
1. mysolution: use map<nums[i], vector<int> (its occured index))
2. solution2: use 2 maps, one map is for freq, another one is store first occurence of each number
*/
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        // find index of first occurrence and last occurence of maximum freq element
//         unordered_map<int, vector<int>> count;
//         int max = 0, key = 0;
//         for (int i = 0; i < nums.size(); i++) {
//             count[nums[i]].push_back(i);
//             int length = count[nums[i]].size();
//             //cout << nums[i] <<  " "<< length << endl;
//             if (length > max){
//                 max = length;
//                 key = nums[i];
//             }
//             if (length == max ) {
//                 // choose the one that has smaller length 
//                 int size1 = count[nums[i]].back() - count[nums[i]][0];
//                 int size2 = count[key].back() - count[key][0];
//                 if (size1 < size2){
//                     key = nums[i];
//                 }
                    
//             }
//         }
      
//         return (count[key].back() - count[key][0] + 1);
        
        unordered_map<int, int> count, first;
        int res = 0, degree = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (first.count(nums[i]) == 0) // count is to check if the element in the map already
                first[nums[i]] = i;
            if (++count[nums[i]] > degree) {
                degree = count[nums[i]];
                res = i - first[nums[i]] + 1;
            } else if (count[nums[i]] == degree)
                res = min(res, i - first[nums[i]] + 1);
        }
        return res;
        
        
    }
};