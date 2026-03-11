#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    int robLinear(vector<int>& nums, int start, int end) {
        int rob1 = 0, rob2 = 0;
        for (int i = start; i <= end; ++i) {
            int temp = max(nums[i] + rob1, rob2);
            rob1 = rob2;
            rob2 = temp;
        }
        return rob2;
    }
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        return max(robLinear(nums, 0, nums.size() - 2), robLinear(nums, 1, nums.size() - 1));
    }
};
