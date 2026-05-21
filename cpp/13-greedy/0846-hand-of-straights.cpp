#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        map<int, int> count;
        for (int c : hand) count[c]++;
        for (auto& [card, cnt] : count) {
            if (cnt > 0) {
                int need = cnt;
                for (int i = 0; i < groupSize; ++i) {
                    if (count[card + i] < need) return false;
                    count[card + i] -= need;
                }
            }
        }
        return true;
    }
};
