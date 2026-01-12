#include <vector>
#include <unordered_map>
#include <cstdlib>
using namespace std;

class RandomizedSet {
    vector<int> nums;
    unordered_map<int, int> valToIdx;
public:
    RandomizedSet() {}
    bool insert(int val) {
        if (valToIdx.count(val)) return false;
        valToIdx[val] = nums.size();
        nums.push_back(val);
        return true;
    }
    bool remove(int val) {
        if (!valToIdx.count(val)) return false;
        int last = nums.back();
        int idx = valToIdx[val];
        nums[idx] = last;
        valToIdx[last] = idx;
        nums.pop_back();
        valToIdx.erase(val);
        return true;
    }
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};
