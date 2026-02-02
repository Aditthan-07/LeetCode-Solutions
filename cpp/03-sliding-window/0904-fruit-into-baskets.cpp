#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> count;
        int l = 0, maxFruits = 0;
        for (int r = 0; r < fruits.size(); ++r) {
            count[fruits[r]]++;
            while (count.size() > 2) {
                if (--count[fruits[l]] == 0) count.erase(fruits[l]);
                l++;
            }
            maxFruits = max(maxFruits, r - l + 1);
        }
        return maxFruits;
    }
};
