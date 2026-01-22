#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";
        vector<int> need(128, 0);
        for (char c : t) need[c]++;
        int required = 0;
        for (int n : need) if (n > 0) required++;
        int l = 0, formed = 0, minLen = 1e9, startIdx = 0;
        vector<int> window(128, 0);
        for (int r = 0; r < s.size(); ++r) {
            char c = s[r];
            window[c]++;
            if (need[c] > 0 && window[c] == need[c]) formed++;
            while (l <= r && formed == required) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    startIdx = l;
                }
                char leftC = s[l];
                window[leftC]--;
                if (need[leftC] > 0 && window[leftC] < need[leftC]) formed--;
                l++;
            }
        }
        return minLen == 1e9 ? "" : s.substr(startIdx, minLen);
    }
};
