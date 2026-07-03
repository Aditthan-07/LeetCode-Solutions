#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> sNums;
        for (int n : nums) sNums.push_back(to_string(n));
        sort(sNums.begin(), sNums.end(), [](const string& a, const string& b) {
            return a + b > b + a;
        });
        if (sNums[0] == "0") return "0";
        string res = "";
        for (const string& s : sNums) res += s;
        return res;
    }
};
