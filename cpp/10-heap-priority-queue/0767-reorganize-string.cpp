#include <string>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        vector<int> count(26, 0);
        for (char c : s) count[c - 'a']++;
        priority_queue<pair<int, char>> pq;
        for (int i = 0; i < 26; ++i) if (count[i] > 0) pq.push({count[i], (char)('a' + i)});
        string res = "";
        pair<int, char> prev = {0, '#'};
        while (!pq.empty()) {
            auto [cnt, ch] = pq.top(); pq.pop();
            res += ch;
            if (prev.first > 0) pq.push(prev);
            cnt--;
            prev = {cnt, ch};
        }
        return res.size() == s.size() ? res : "";
    }
};
