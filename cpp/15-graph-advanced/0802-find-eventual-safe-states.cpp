#include <vector>
using namespace std;

class Solution {
    bool dfs(const vector<vector<int>>& graph, int u, vector<int>& state) {
        if (state[u] > 0) return state[u] == 2;
        state[u] = 1;
        for (int v : graph[u]) {
            if (state[v] == 2) continue;
            if (state[v] == 1 || !dfs(graph, v, state)) return false;
        }
        state[u] = 2;
        return true;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> state(n, 0), res;
        for (int i = 0; i < n; ++i) if (dfs(graph, i, state)) res.push_back(i);
        return res;
    }
};
