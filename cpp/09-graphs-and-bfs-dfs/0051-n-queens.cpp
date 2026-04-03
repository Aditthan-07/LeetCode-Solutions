#include <vector>
#include <string>
using namespace std;

class Solution {
    void backtrack(int r, int n, vector<string>& board, vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2, vector<vector<string>>& res) {
        if (r == n) {
            res.push_back(board);
            return;
        }
        for (int c = 0; c < n; ++c) {
            if (cols[c] || diag1[r + c] || diag2[r - c + n - 1]) continue;
            board[r][c] = 'Q';
            cols[c] = diag1[r + c] = diag2[r - c + n - 1] = true;
            backtrack(r + 1, n, board, cols, diag1, diag2, res);
            board[r][c] = '.';
            cols[c] = diag1[r + c] = diag2[r - c + n - 1] = false;
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        vector<bool> cols(n, false), diag1(2 * n - 1, false), diag2(2 * n - 1, false);
        backtrack(0, n, board, cols, diag1, diag2, res);
        return res;
    }
};
