#include <string>
using namespace std;

class Solution {
    int countPali(const string& s, int l, int r) {
        int res = 0;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            res++;
            l--; r++;
        }
        return res;
    }
public:
    int countSubstrings(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            res += countPali(s, i, i);
            res += countPali(s, i, i + 1);
        }
        return res;
    }
};
