#include <map>
#include <algorithm>
using namespace std;

class MyCalendarThree {
    map<int, int> timeline;
public:
    MyCalendarThree() {}
    int book(int start, int end) {
        timeline[start]++;
        timeline[end]--;
        int maxK = 0, ongoing = 0;
        for (auto& [t, delta] : timeline) {
            ongoing += delta;
            maxK = max(maxK, ongoing);
        }
        return maxK;
    }
};
