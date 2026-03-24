#include <vector>
using namespace std;

class Solution {
    void dfs(const vector<vector<int>>& heights, vector<vector<bool>>& ocean, int r, int c) {
        ocean[r][c] = true;
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto& d : dirs) {
            int nr = r + d[0], nc = c + d[1];
            if (nr >= 0 && nc >= 0 && nr < heights.size() && nc < heights[0].size() &&
                !ocean[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                dfs(heights, ocean, nr, nc);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> atl(m, vector<bool>(n, false));
        for (int r = 0; r < m; ++r) {
            dfs(heights, pac, r, 0);
            dfs(heights, atl, r, n - 1);
        }
        for (int c = 0; c < n; ++c) {
            dfs(heights, pac, 0, c);
            dfs(heights, atl, m - 1, c);
        }
        vector<vector<int>> res;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (pac[r][c] && atl[r][c]) res.push_back({r, c});
            }
        }
        return res;
    }
};
