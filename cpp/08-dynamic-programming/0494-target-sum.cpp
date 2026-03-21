#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > total || (total + target) % 2 != 0) return 0;
        int s1 = (total + target) / 2;
        vector<int> dp(s1 + 1, 0);
        dp[0] = 1;
        for (int n : nums) {
            for (int i = s1; i >= n; --i) {
                dp[i] += dp[i - n];
            }
        }
        return dp[s1];
    }
};
