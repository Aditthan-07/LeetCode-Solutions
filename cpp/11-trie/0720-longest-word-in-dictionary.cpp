#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        unordered_set<string> built;
        string res = "";
        for (const string& w : words) {
            if (w.size() == 1 || built.count(w.substr(0, w.size() - 1))) {
                built.insert(w);
                if (w.size() > res.size()) res = w;
            }
        }
        return res;
    }
};
