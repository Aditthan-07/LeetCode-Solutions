#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int i = 0, n = events.size(), day = 0, res = 0;
        while (i < n || !minHeap.empty()) {
            if (minHeap.empty()) day = events[i][0];
            while (i < n && events[i][0] <= day) {
                minHeap.push(events[i][1]);
                i++;
            }
            minHeap.pop();
            res++;
            day++;
            while (!minHeap.empty() && minHeap.top() < day) minHeap.pop();
        }
        return res;
    }
};
