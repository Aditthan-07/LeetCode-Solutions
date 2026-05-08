#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> count;
        for (const string& w : words) count[w]++;
        auto cmp = [](const pair<string, int>& a, const pair<string, int>& b) {
            return a.second == b.second ? a.first > b.first : a.second < b.second;
        };
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> pq(cmp);
        for (auto& p : count) pq.push(p);
        vector<string> res;
        while (k-- > 0 && !pq.empty()) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};
