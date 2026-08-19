#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
    int dfs(vector<vector<int>>& grid, int r, int c, int id) {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] != 1) return 0;
        grid[r][c] = id;
        return 1 + dfs(grid, r+1, c, id) + dfs(grid, r-1, c, id) + dfs(grid, r, c+1, id) + dfs(grid, r, c-1, id);
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size(), id = 2, maxArea = 0;
        unordered_map<int, int> area;
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    area[id] = dfs(grid, r, c, id);
                    maxArea = max(maxArea, area[id]);
                    id++;
                }
            }
        }
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 0) {
                    unordered_set<int> neighborIslands;
                    for (auto& d : dirs) {
                        int nr = r + d[0], nc = c + d[1];
                        if (nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] > 1) {
                            neighborIslands.insert(grid[nr][nc]);
                        }
                    }
                    int combined = 1;
                    for (int nid : neighborIslands) combined += area[nid];
                    maxArea = max(maxArea, combined);
                }
            }
        }
        return maxArea;
    }
};
