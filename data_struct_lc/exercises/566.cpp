// https://leetcode.com/problems/reshape-the-matrix/
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        // not possible
        int ori_row = nums.size();
        int ori_col = nums[0].size();
        if (r*c != ori_row*ori_col)
            return nums;
        
        // if possible
        vector<vector<int>> res(r, std::vector<int>(c,0));

       // cout << res[0][0]<<endl;
       
        int row = 0;
        int col = 0;
        for(int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
               
                if (col >= ori_col) {
                    row++;
                    col = 0;
                }
                if (row == ori_row)
                    break;
                               
                res[i][j] = nums[row][col++];    
            }
        }
        
        return res;
    }
};


// solution 2: 
// int m = nums.size(), n = nums[0].size(), o = m * n;
// if (r * c != o) return nums;
// vector<vector<int>> res(r, vector<int>(c, 0));
// for (int i = 0; i < o; i++) 
//      res[i / c][i % c] = nums[i / n][i % n];
// return res;