#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> b;
        b.push_back(1);
        for (int n : nums) if (n > 0) b.push_back(n);
        b.push_back(1);
        int n = b.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int len = 2; len < n; ++len) {
            for (int l = 0; l < n - len; ++l) {
                int r = l + len;
                for (int i = l + 1; i < r; ++i) {
                    dp[l][r] = max(dp[l][r], b[l] * b[i] * b[r] + dp[l][i] + dp[i][r]);
                }
            }
        }
        return dp[0][n - 1];
    }
};
