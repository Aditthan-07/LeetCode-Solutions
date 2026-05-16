#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (const auto& meeting : intervals) {
            if (!minHeap.empty() && minHeap.top() <= meeting[0]) minHeap.pop();
            minHeap.push(meeting[1]);
        }
        return minHeap.size();
    }
};
