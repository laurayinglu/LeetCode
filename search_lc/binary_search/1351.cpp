// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int res = 0;
        int m = grid.size();
        int n = grid[0].size();
        int s = 0;
        for (int i = 0; i < m; i++) {
            if(grid[i][0] < 0) {
                res+= n;
                continue;
            }
            for (int j = 0; j < n; j++) {
                if(grid[i][j] < 0){
                    res++;
                }
            }
        }
        
        return res;
        
        // solution 2
        // start from top right
        int i = 0;
        int j = n-1;
        while (i < m && j >=0){
            if (grid[i][j] < 0){
                res += (m-i);
                j--;
            }else {
                i++;
            }
        }
        
        
        return res;
        
    }
};

// 4  3  2 -1
// 3  2  1 -1
// 1  1 -1 -2
//-1 -1 -2 -3