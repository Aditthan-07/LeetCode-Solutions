#include <vector>
using namespace std;

class Solution {
    int find(int x, vector<int>& parent) {
        if (parent[x] != x) parent[x] = find(parent[x], parent);
        return parent[x];
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);
        for (int i = 1; i <= n; ++i) parent[i] = i;
        for (const auto& e : edges) {
            int p1 = find(e[0], parent), p2 = find(e[1], parent);
            if (p1 == p2) return e;
            parent[p1] = p2;
        }
        return {};
    }
};
