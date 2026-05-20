class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) {
            return -1;
        }
        queue<pair<int, pair<int,int>>> q;
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        dist[0][0] = 1;
        q.push({1, {0, 0}});
        // 8 directions
        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        while(!q.empty()) {
            int d = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            // reached destination
            if(row == n-1 && col == n-1) {
                return d;
            }
            for(int i = 0; i < 8; i++) {

                int nrow = row + dr[i];
                int ncol = col + dc[i];

                // valid cell check
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n &&
                   grid[nrow][ncol] == 0 &&
                   d + 1 < dist[nrow][ncol]) {
                    dist[nrow][ncol] = d + 1;
                    q.push({d + 1, {nrow, ncol}});
                }
            }
        }
        return -1;
    }
};
