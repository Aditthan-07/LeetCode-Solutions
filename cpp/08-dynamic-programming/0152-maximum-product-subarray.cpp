#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curMax = 1, curMin = 1, res = nums[0];
        for (int n : nums) {
            if (n < 0) swap(curMax, curMin);
            curMax = max(n, curMax * n);
            curMin = min(n, curMin * n);
            res = max(res, curMax);
        }
        return res;
    }
};
