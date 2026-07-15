#include <vector>
using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int total = 0, n = nums.size();
        for (int i = 0; i < 32; ++i) {
            int countOnes = 0;
            for (int num : nums) countOnes += ((num >> i) & 1);
            total += countOnes * (n - countOnes);
        }
        return total;
    }
};
