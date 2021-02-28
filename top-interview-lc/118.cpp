// https://leetcode.com/problems/pascals-triangle/

// DP: Although the algorithm is very simple, the iterative approach to constructing Pascal's triangle 
// can be classified as dynamic programming because we construct each row based on the previous row.

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if (numRows == 1){
           return {{1}};
        }
        
        if (numRows == 2){
           return {{1},{1,1}};
        }
        
        res.push_back({1});
        res.push_back({1,1});
        for(int i = 2; i < numRows; i++) {
            vector<int> row(i+1);
            row[0] = 1;
            row[i] = 1;
            for (int j = 1; j < i; j++) {
                row[j] = res[i-1][j-1] + res[i-1][j];
            }
            
            res.push_back(row);
        }
        
        return res;    
        
    }
};

//  vector<vector<int>> res(numRows);
        
//         for (int i = 0; i < numRows; i++) {
//             res[i].resize(i+1);
//             res[i][0] = res[i][i] = 1;
//             for (int j = 1; j < i; j++) {
//                 res[i][j] = res[i-1][j-1] + res[i-1][j];
//             }
//         }
        
//         return res;