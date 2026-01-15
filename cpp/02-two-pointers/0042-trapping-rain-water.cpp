#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int maxL = 0, maxR = 0, trapped = 0;
        while (l < r) {
            if (height[l] <= height[r]) {
                if (height[l] >= maxL) maxL = height[l];
                else trapped += maxL - height[l];
                l++;
            } else {
                if (height[r] >= maxR) maxR = height[r];
                else trapped += maxR - height[r];
                r--;
            }
        }
        return trapped;
    }
};
