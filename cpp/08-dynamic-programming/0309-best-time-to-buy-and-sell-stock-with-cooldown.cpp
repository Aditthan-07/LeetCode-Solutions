#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sold = 0, rest = 0, hold = -1e9;
        for (int p : prices) {
            int prevSold = sold;
            sold = hold + p;
            hold = max(hold, rest - p);
            rest = max(rest, prevSold);
        }
        return max(sold, rest);
    }
};
