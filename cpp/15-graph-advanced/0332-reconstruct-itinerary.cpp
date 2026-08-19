#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;
    vector<string> route;
    void dfs(const string& u) {
        while (!adj[u].empty()) {
            string v = adj[u].top(); adj[u].pop();
            dfs(v);
        }
        route.push_back(u);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (const auto& t : tickets) adj[t[0]].push(t[1]);
        dfs("JFK");
        reverse(route.begin(), route.end());
        return route;
    }
};
