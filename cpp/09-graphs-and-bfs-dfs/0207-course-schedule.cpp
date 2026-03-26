#include <vector>
using namespace std;

class Solution {
    bool hasCycle(int node, const vector<vector<int>>& adj, vector<int>& visited) {
        visited[node] = 1;
        for (int neighbor : adj[node]) {
            if (visited[neighbor] == 1) return true;
            if (visited[neighbor] == 0 && hasCycle(neighbor, adj, visited)) return true;
        }
        visited[node] = 2;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (const auto& p : prerequisites) adj[p[1]].push_back(p[0]);
        vector<int> visited(numCourses, 0);
        for (int i = 0; i < numCourses; ++i) {
            if (visited[i] == 0 && hasCycle(i, adj, visited)) return false;
        }
        return true;
    }
};
