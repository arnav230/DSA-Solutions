class Solution {
public:

    void dfs(int row, int col, vector<vector<int>>& image,
             vector<vector<int>>& ans, int newColor,
             int delRow[], int delCol[], int initialColor) {

        ans[row][col] = newColor;
      
        int n = image.size();
        int m = image[0].size();
        for(int i = 0; i < 4; i++) {

            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(nrow >= 0 && nrow < n &&
               ncol >= 0 && ncol < m &&
               image[nrow][ncol] == initialColor &&
               ans[nrow][ncol] != newColor) {
                dfs(nrow, ncol, image, ans, newColor,
                    delRow, delCol, initialColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        vector<vector<int>> ans = image;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        dfs(sr, sc, image, ans, color,
            delRow, delCol, initialColor);
        return ans;
    }
};
