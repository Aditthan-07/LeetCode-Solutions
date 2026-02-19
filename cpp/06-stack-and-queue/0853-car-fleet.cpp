#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars(n);
        for (int i = 0; i < n; ++i) {
            cars[i] = {position[i], (double)(target - position[i]) / speed[i]};
        }
        sort(cars.rbegin(), cars.rend());
        int fleets = 0;
        double maxTime = 0.0;
        for (const auto& c : cars) {
            if (c.second > maxTime) {
                fleets++;
                maxTime = c.second;
            }
        }
        return fleets;
    }
};
