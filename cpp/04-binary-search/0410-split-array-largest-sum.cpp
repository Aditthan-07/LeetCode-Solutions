#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        long long l = *max_element(nums.begin(), nums.end());
        long long r = accumulate(nums.begin(), nums.end(), 0LL);
        long long res = r;
        while (l <= r) {
            long long mid = l + (r - l) / 2;
            int pieces = 1;
            long long curSum = 0;
            for (int x : nums) {
                if (curSum + x > mid) {
                    pieces++;
                    curSum = x;
                } else {
                    curSum += x;
                }
            }
            if (pieces <= k) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
};
