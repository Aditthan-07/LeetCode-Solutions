#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int count = 1;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : rooms[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    count++;
                    q.push(v);
                }
            }
        }
        return count == n;
    }
};
