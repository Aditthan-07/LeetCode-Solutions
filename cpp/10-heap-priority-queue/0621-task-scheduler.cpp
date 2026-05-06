#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for (char c : tasks) count[c - 'A']++;
        int maxCount = *max_element(count.begin(), count.end());
        int maxCountFreq = 0;
        for (int c : count) if (c == maxCount) maxCountFreq++;
        int emptySlots = (maxCount - 1) * (n + 1) + maxCountFreq;
        return max((int)tasks.size(), emptySlots);
    }
};
