#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<vector<int>> indexedTasks(n);
        for (int i = 0; i < n; ++i) indexedTasks[i] = {tasks[i][0], tasks[i][1], i};
        sort(indexedTasks.begin(), indexedTasks.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> res;
        long long time = 0;
        int i = 0;
        while (i < n || !pq.empty()) {
            if (pq.empty() && time < indexedTasks[i][0]) time = indexedTasks[i][0];
            while (i < n && indexedTasks[i][0] <= time) {
                pq.push({indexedTasks[i][1], indexedTasks[i][2]});
                i++;
            }
            auto [procTime, idx] = pq.top(); pq.pop();
            time += procTime;
            res.push_back(idx);
        }
        return res;
    }
};
