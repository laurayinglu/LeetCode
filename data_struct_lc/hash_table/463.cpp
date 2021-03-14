// https://leetcode.com/problems/island-perimeter/
// 1. find how many 1 in the map. If without the consideration of surrounding cells, the total perimeter should be the total amount of 1 times 4.
// 2. find how many cell walls that connect with both lands. We need to deduct twice of those lines from total perimeter

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int count = 0;
        int repeat = 0;
        
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    count++;
                    
                    if (i != 0 && grid[i-1][j] == 1)
                        repeat++;
                    if (j != 0 && grid[i][j-1] == 1)
                        repeat++;
                }
            }
        }
        
        return count*4-repeat*2;
    }
};