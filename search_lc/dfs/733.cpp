// https://leetcode.com/problems/flood-fill/

class Solution {
public:
    void update(vector<vector<int>>& image, int sr, int sc, int color, int newColor) {
        //cout << sr << " "<< sc<< endl;
        int r = image.size();
        int c = image[0].size();
        if (image[sr][sc] == color) {
            image[sr][sc] = newColor;
            // up
            if (sr >= 1) 
                update(image, sr-1, sc, color, newColor);
            // down
            if (sr+1 < r)
                update(image, sr+1, sc, color,  newColor);
            // left
            if (sc >= 1)
                update(image, sr, sc-1, color,  newColor);
            // right
            if (sc+1 < c) 
                update(image, sr, sc+1, color, newColor);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int color = image[sr][sc];
        if (color != newColor)
            update(image, sr, sc, color, newColor);
        return image;
    }

};

// class Solution {
// public:
//     void dfs(vector<vector<int>>& image, int i, int j, int color, int newColor) {
//         if (i < 0 || j < 0 || i >= image.size() || j >= image[0].size() || image[i][j] != color) return;
//         image[i][j] = newColor;
//         dfs(image, i, j - 1, color, newColor);
//         dfs(image, i, j + 1, color, newColor);
//         dfs(image, i - 1, j, color, newColor);
//         dfs(image, i + 1, j, color, newColor);

//     }
    
//     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
//         int color = image[sr][sc];
//         if (color != newColor)
//             dfs(image, sr, sc, color, newColor);
//         return image;
//     }
    
    
// };