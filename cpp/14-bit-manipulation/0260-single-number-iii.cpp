#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long diff = 0;
        for (int x : nums) diff ^= x;
        diff &= -diff;
        vector<int> res = {0, 0};
        for (int x : nums) {
            if ((x & diff) == 0) res[0] ^= x;
            else res[1] ^= x;
        }
        return res;
    }
};
