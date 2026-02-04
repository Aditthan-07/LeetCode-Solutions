#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class TimeMap {
    unordered_map<string, vector<pair<int, string>>> store;
public:
    TimeMap() {}
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    string get(string key, int timestamp) {
        if (!store.count(key)) return "";
        const auto& list = store[key];
        int l = 0, r = list.size() - 1;
        string res = "";
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (list[mid].first <= timestamp) {
                res = list[mid].second;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return res;
    }
};
