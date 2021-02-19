// https://leetcode.com/problems/matrix-cells-in-distance-order/

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        
         auto comp = [r0, c0](vector<int> &a, vector<int> &b)
        {
            return abs(a[0]-r0) + abs(a[1]-c0) < abs(b[0]-r0) + abs(b[1]-c0);
        };
        
        vector<vector<int>> resp;
        for(int i=0 ; i<R ; i++)
        {
            for(int j=0; j<C ; j++)
            {
                resp.push_back({i, j});
            }
        }
        
               
        // for(int i=0 ; i<R ; i++)
        // {
        //     for(int j=0; j<resp[i].size() ; j++)
        //     {
        //         cout << resp[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        sort(resp.begin(), resp.end(), comp);

        return resp;
    }
}; 