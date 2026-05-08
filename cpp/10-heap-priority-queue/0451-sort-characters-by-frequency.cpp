#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> count;
        for (char c : s) count[c]++;
        priority_queue<pair<int, char>> pq;
        for (auto& p : count) pq.push({p.second, p.first});
        string res = "";
        while (!pq.empty()) {
            auto [freq, ch] = pq.top(); pq.pop();
            res.append(freq, ch);
        }
        return res;
    }
};
