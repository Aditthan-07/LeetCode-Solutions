#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> res;
        string prefix = "";
        auto it = products.begin();
        for (char c : searchWord) {
            prefix += c;
            it = lower_bound(it, products.end(), prefix);
            vector<string> suggestions;
            for (int i = 0; i < 3 && it + i < products.end(); ++i) {
                string s = *(it + i);
                if (s.substr(0, prefix.size()) == prefix) suggestions.push_back(s);
                else break;
            }
            res.push_back(suggestions);
        }
        return res;
    }
};
