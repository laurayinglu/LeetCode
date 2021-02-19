// https://leetcode.com/problems/max-chunks-to-make-sorted/
// 
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int res = 0;
        int max = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > max)
                max = arr[i];
            
            if (max == i)
                res++;
        }
        
        return res;
    }
};