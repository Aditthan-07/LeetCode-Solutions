#include <map>
using namespace std;

class MyCalendar {
    map<int, int> books;
public:
    MyCalendar() {}
    bool book(int start, int end) {
        auto next = books.lower_bound(start);
        if (next != books.end() && next->first < end) return false;
        if (next != books.begin() && prev(next)->second > start) return false;
        books[start] = end;
        return true;
    }
};
