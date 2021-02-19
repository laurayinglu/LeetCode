// https://leetcode.com/problems/search-a-2d-matrix-ii/
// divide-and-conquer
// we can search from bottom-left or top-right
// top-right: if target is greater, then we move down, if target is smaller then we move left
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) {
           return false;
        }
        int n = matrix[0].size();
        int i = 0, j = n - 1;
        while (i < m && j >= 0) {
            if (matrix[i][j] == target) {
                return true;
            } 
            else if (matrix[i][j] > target) {
               --j;
            } 
            else 
                ++i;
        }
        return false;
    }
};