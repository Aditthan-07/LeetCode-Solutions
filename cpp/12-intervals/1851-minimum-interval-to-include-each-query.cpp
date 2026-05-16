#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());
        vector<pair<int, int>> sortedQ(queries.size());
        for (int i = 0; i < queries.size(); ++i) sortedQ[i] = {queries[i], i};
        sort(sortedQ.begin(), sortedQ.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> res(queries.size());
        int i = 0, n = intervals.size();
        for (auto& [q, idx] : sortedQ) {
            while (i < n && intervals[i][0] <= q) {
                pq.push({intervals[i][1] - intervals[i][0] + 1, intervals[i][1]});
                i++;
            }
            while (!pq.empty() && pq.top().second < q) pq.pop();
            res[idx] = pq.empty() ? -1 : pq.top().first;
        }
        return res;
    }
};
