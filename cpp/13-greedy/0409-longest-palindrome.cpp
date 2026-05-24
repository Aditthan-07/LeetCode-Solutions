#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> count(128, 0);
        for (char c : s) count[c]++;
        int ans = 0;
        bool hasOdd = false;
        for (int c : count) {
            ans += (c / 2) * 2;
            if (c % 2 == 1) hasOdd = true;
        }
        return hasOdd ? ans + 1 : ans;
    }
};
