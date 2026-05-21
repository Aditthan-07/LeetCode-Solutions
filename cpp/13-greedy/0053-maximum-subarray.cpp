#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0], curSum = 0;
        for (int n : nums) {
            curSum = max(n, curSum + n);
            maxSum = max(maxSum, curSum);
        }
        return maxSum;
    }
};
