#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
    int cap;
    list<pair<int, int>> lru;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
public:
    LRUCache(int capacity) : cap(capacity) {}
    int get(int key) {
        if (!mp.count(key)) return -1;
        lru.splice(lru.begin(), lru, mp[key]);
        return mp[key]->second;
    }
    void put(int key, int value) {
        if (mp.count(key)) {
            lru.splice(lru.begin(), lru, mp[key]);
            mp[key]->second = value;
            return;
        }
        if (lru.size() == cap) {
            int oldKey = lru.back().first;
            lru.pop_back();
            mp.erase(oldKey);
        }
        lru.push_front({key, value});
        mp[key] = lru.begin();
    }
};
