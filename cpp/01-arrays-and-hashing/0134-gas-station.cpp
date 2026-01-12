#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0, curTank = 0, start = 0;
        for (int i = 0; i < gas.size(); ++i) {
            totalGas += gas[i];
            totalCost += cost[i];
            curTank += gas[i] - cost[i];
            if (curTank < 0) {
                start = i + 1;
                curTank = 0;
            }
        }
        return (totalGas >= totalCost) ? start : -1;
    }
};
