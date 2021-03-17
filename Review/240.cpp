// https://leetcode.com/problems/search-a-2d-matrix-ii/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        if (m <= 0)
            return false;
        int r = 0;
        int c = n-1;
        
        while (r < m && c >= 0) {
            if (target < matrix[r][c])
                c--;
            else if (target == matrix[r][c])
                return true;
            else
                r++;
        }
        
        return false;
    }
};