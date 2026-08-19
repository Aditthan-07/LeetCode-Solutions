#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> inDegree;
        for (const string& w : words) for (char c : w) inDegree[c] = 0;
        for (int i = 0; i < (int)words.size() - 1; ++i) {
            string w1 = words[i], w2 = words[i + 1];
            if (w1.size() > w2.size() && w1.substr(0, w2.size()) == w2) return "";
            for (int j = 0; j < min(w1.size(), w2.size()); ++j) {
                if (w1[j] != w2[j]) {
                    if (!adj[w1[j]].count(w2[j])) {
                        adj[w1[j]].insert(w2[j]);
                        inDegree[w2[j]]++;
                    }
                    break;
                }
            }
        }
        queue<char> q;
        for (auto& [c, d] : inDegree) if (d == 0) q.push(c);
        string res = "";
        while (!q.empty()) {
            char u = q.front(); q.pop();
            res += u;
            for (char v : adj[u]) if (--inDegree[v] == 0) q.push(v);
        }
        return res.size() == inDegree.size() ? res : "";
    }
};
