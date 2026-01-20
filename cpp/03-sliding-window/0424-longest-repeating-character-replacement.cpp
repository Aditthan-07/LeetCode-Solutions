#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int maxCount = 0, maxLen = 0, l = 0;
        for (int r = 0; r < s.size(); ++r) {
            maxCount = max(maxCount, ++count[s[r] - 'A']);
            while ((r - l + 1) - maxCount > k) {
                count[s[l++] - 'A']--;
            }
            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
    }
};
