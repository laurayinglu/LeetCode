// https://leetcode.com/problems/rotate-image/
// solution1: rotate each number by 90 degree
// solution2: transpose + flip
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // int temp = 0, n = matrix.size()-1;
        // for (int i = 0; i <= n / 2; ++i) {
        //    for (int j = i; j < n - i; ++j) {
        //        temp = matrix[j][n-i];
        //        matrix[j][n-i] = matrix[i][j];
        //        matrix[i][j] = matrix[n-j][i];
        //        matrix[n-j][i] = matrix[n-i][n-j];
        //        matrix[n-i][n-j] = temp;
        //     } 
        // }
        
        
        // solution2: first transpose then flip horizontally
        
        int size = matrix.size();
        int temp = 0;
        // tranpose
        for (int i = 0; i < size; i++) {
            for (int j = i; j < matrix[i].size(); j++) {
                temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        
        // flip 
        for (int i = 0; i < size; i++) {
            for (int j = 0 ; j < matrix[i].size()/2; j++) {
                temp = matrix[i][j];
                matrix[i][j] = matrix[i][size-1-j];
                matrix[i][size-1-j] = temp;
            }
        }
    }
};