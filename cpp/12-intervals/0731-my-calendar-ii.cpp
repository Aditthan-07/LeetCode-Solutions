#include <map>
using namespace std;

class MyCalendarTwo {
    map<int, int> timeline;
public:
    MyCalendarTwo() {}
    bool book(int start, int end) {
        timeline[start]++;
        timeline[end]--;
        int ongoing = 0;
        for (auto& [t, delta] : timeline) {
            ongoing += delta;
            if (ongoing >= 3) {
                timeline[start]--;
                timeline[end]++;
                return false;
            }
        }
        return true;
    }
};
