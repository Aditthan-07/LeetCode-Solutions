#include <vector>
using namespace std;

class Solution {
    void dfs(vector<vector<char>>& board, int r, int c) {
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] != 'O') return;
        board[r][c] = '#';
        dfs(board, r + 1, c);
        dfs(board, r - 1, c);
        dfs(board, r, c + 1);
        dfs(board, r, c - 1);
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        for (int r = 0; r < m; ++r) {
            if (board[r][0] == 'O') dfs(board, r, 0);
            if (board[r][n - 1] == 'O') dfs(board, r, n - 1);
        }
        for (int c = 0; c < n; ++c) {
            if (board[0][c] == 'O') dfs(board, 0, c);
            if (board[m - 1][c] == 'O') dfs(board, m - 1, c);
        }
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (board[r][c] == 'O') board[r][c] = 'X';
                else if (board[r][c] == '#') board[r][c] = 'O';
            }
        }
    }
};
