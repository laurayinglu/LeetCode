// https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        // sort the arr first
        sort(arr.begin(), arr.end());
        
        bool res = true;
        int diff = arr[1] - arr[0];
        for (int i = 1; i < arr.size()-1; i++) {
            if ((arr[i+1] - arr[i]) != diff) {
                res = false;
            }
        }
        
        return res;
    }
};