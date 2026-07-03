#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() && k > 0 && nums[i] < 0; ++i) {
            nums[i] = -nums[i];
            k--;
        }
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int minVal = *min_element(nums.begin(), nums.end());
        if (k % 2 == 1) sum -= 2 * minVal;
        return sum;
    }
};
